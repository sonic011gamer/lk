#include "splash.h"
#include <debug.h>
#include <string.h>
#include <stdlib.h>

#include <partition_parser.h>
#include <dev/flash.h>
#include <lib/ptable.h>
#include <sys/types.h>
#include <target.h>

static uint8_t logo_header[LOGO_IMG_HEADER_SIZE];

int splash_screen_check_header(logo_img_header *header)
{
	if (memcmp(header->magic, LOGO_IMG_MAGIC, 8))
		return -1;
	if (header->width == 0 || header->height == 0)
		return -1;
	return 0;
}

int splash_screen_flash()
{
	struct ptentry *ptn;
	struct ptable *ptable;
	struct logo_img_header *header;
	struct fbcon_config *fb_display = NULL;

	ptable = flash_get_ptable();
	if (ptable == NULL) {
		dprintf(CRITICAL, "ERROR: Partition table not found\n");
		return -1;
	}

	ptn = ptable_find(ptable, "splash");
	if (ptn == NULL) {
		dprintf(CRITICAL, "ERROR: splash Partition not found\n");
		return -1;
	}
	if (flash_read(ptn, 0, (void *)logo_header, LOGO_IMG_HEADER_SIZE)) {
		dprintf(CRITICAL, "ERROR: Cannot read boot image header\n");
		return -1;
	}

	header = (struct logo_img_header *)logo_header;
	if (splash_screen_check_header(header)) {
		dprintf(CRITICAL, "ERROR: Boot image header invalid\n");
		return -1;
	}

	fb_display = fbcon_display();
	if (fb_display) {
		if (header->type && (header->blocks != 0)) { // RLE24 compressed data
			uint8_t *base = (uint8_t *) fb_display->base + LOGO_IMG_OFFSET;

			/* if the logo is full-screen size, remove "fbcon_clear()" */
			if ((header->width != fb_display->width)
						|| (header->height != fb_display->height))
					fbcon_clear();

			if (flash_read(ptn + LOGO_IMG_HEADER_SIZE, 0,
				(uint32_t *)base,
				(header->blocks * 512))) {
				dprintf(CRITICAL, "ERROR: Cannot read splash image from partition\n");
				return -1;
			}
			fbcon_extract_to_screen(header, base);
			return 0;
		}

		if ((header->width > fb_display->width) || (header->height > fb_display->height)) {
			dprintf(CRITICAL, "Logo config greater than fb config. Fall back default logo\n");
			return -1;
		}

		uint8_t *base = (uint8_t *) fb_display->base;
		if (flash_read(ptn + LOGO_IMG_HEADER_SIZE, 0,
			(uint32_t *)base,
			((((header->width * header->height * fb_display->bpp/8) + 511) >> 9) << 9))) {
			fbcon_clear();
			dprintf(CRITICAL, "ERROR: Cannot read splash image from partition\n");
			return -1;
		}
	}

	return 0;
}

int splash_screen_mmc()
{
	int index = INVALID_PTN;
	unsigned long long ptn = 0;
	struct fbcon_config *fb_display = NULL;
	struct logo_img_header *header;
	uint32_t blocksize, realsize, readsize;
	uint8_t *base;

	index = partition_get_index("splash");
	if (index == 0) {
		dprintf(CRITICAL, "ERROR: splash Partition table not found\n");
		return -1;
	}

	ptn = partition_get_offset(index);
	if (ptn == 0) {
		dprintf(CRITICAL, "ERROR: splash Partition invalid\n");
		return -1;
	}

	mmc_set_lun(partition_get_lun(index));

	blocksize = mmc_get_device_blocksize();
	if (blocksize == 0) {
		dprintf(CRITICAL, "ERROR:splash Partition invalid blocksize\n");
		return -1;
	}

	fb_display = fbcon_display();
	if (!fb_display)
	{
		dprintf(CRITICAL, "ERROR: fb config is not allocated\n");
		return -1;
	}

	base = (uint8_t *) fb_display->base;

	if (mmc_read(ptn, (uint32_t *)(base + LOGO_IMG_OFFSET), blocksize)) {
		dprintf(CRITICAL, "ERROR: Cannot read splash image header\n");
		return -1;
	}

	header = (struct logo_img_header *)(base + LOGO_IMG_OFFSET);
	if (splash_screen_check_header(header)) {
		dprintf(CRITICAL, "ERROR: Splash image header invalid\n");
		return -1;
	}

	if (fb_display) {
		if (header->type && (header->blocks != 0)) { /* 1 RLE24 compressed data */
			base += LOGO_IMG_OFFSET;

			realsize =  header->blocks * 512;
			readsize =  ROUNDUP((realsize + LOGO_IMG_HEADER_SIZE), blocksize) - blocksize;

			/* if the logo is not full-screen size, clean screen */
			if ((header->width != fb_display->width)
						|| (header->height != fb_display->height))
				fbcon_clear();

			if (mmc_read(ptn + blocksize, (uint32_t *)(base + blocksize), readsize)) {
				dprintf(CRITICAL, "ERROR: Cannot read splash image from partition\n");
				return -1;
			}

			fbcon_extract_to_screen(header, (base + LOGO_IMG_HEADER_SIZE));
		} else { /* 2 Raw BGR data */

			if ((header->width > fb_display->width) || (header->height > fb_display->height)) {
				dprintf(CRITICAL, "Logo config greater than fb config. Fall back default logo\n");
				return -1;
			}

			realsize =  header->width * header->height * fb_display->bpp / 8;
			readsize =  ROUNDUP((realsize + LOGO_IMG_HEADER_SIZE), blocksize) - blocksize;

			if (blocksize == LOGO_IMG_HEADER_SIZE) { /* read the content directly */
				if (mmc_read((ptn + LOGO_IMG_HEADER_SIZE), (uint32_t *)base, readsize)) {
					fbcon_clear();
					dprintf(CRITICAL, "ERROR: Cannot read splash image from partition\n");
					return -1;
				}
			} else {
				if (mmc_read(ptn + blocksize ,
						(uint32_t *)(base + LOGO_IMG_OFFSET + blocksize), readsize)) {
					dprintf(CRITICAL, "ERROR: Cannot read splash image from partition\n");
					return -1;
				}
				memmove(base, (base + LOGO_IMG_OFFSET + LOGO_IMG_HEADER_SIZE), realsize);
			}
		}
	}

	return 0;
}

int fetch_image_from_partition()
{
	if (target_is_emmc_boot()) {
		return splash_screen_mmc();
	} else {
		return splash_screen_flash();
	}
}
