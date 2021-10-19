/*
 * Copyright (c) 2009, Google Inc.
 * All rights reserved.
 *
 * Copyright (c) 2009-2014, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of The Linux Foundation nor
 *       the names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <common.h>
#include <debug.h>
#include <platform.h>
#include <malloc.h>
#include <app.h>
#include <target.h>
#include <dev/fbcon.h>
#include <platform/timer.h>
#include <kernel/timer.h>
#include <kernel/thread.h>
#include "../aboot/fastboot.h"

#ifdef MEMBASE
#define EMMC_BOOT_IMG_HEADER_ADDR (0xFF000+(MEMBASE))
#else
#define EMMC_BOOT_IMG_HEADER_ADDR 0xFF000
#endif

#ifndef MEMSIZE
#define MEMSIZE 1024*1024
#endif

#define FASTBOOT_MODE   0x77665500
#define FPS 15

static struct fbconfig fb;

void cmd_reboot(const char *arg, void *data, unsigned sz)
{
	dprintf(INFO, "rebooting the device\n");
	fastboot_okay("");
	reboot_device(0);
}

void cmd_reboot_bootloader(const char *arg, void *data, unsigned sz)
{
	dprintf(INFO, "rebooting the device\n");
	fastboot_okay("");
	reboot_device(FASTBOOT_MODE);
}

/*
#if WITH_DEBUG_LOG_BUF
void cmd_oem_lk_log(const char *arg, void *data, unsigned sz)
{
	char* pch;
	char* buf = strdup(lk_log_getbuf());

	pch = strtok(buf, "\n\r");
	while (pch != NULL) {
		char* ptr = pch;
		while(ptr!=NULL) {
			fastboot_info(ptr);
			if(strlen(ptr)>MAX_RSP_SIZE-5)
				ptr+=MAX_RSP_SIZE-5;
			else ptr=NULL;
		}

		pch = strtok(NULL, "\n\r");
	}

	free(buf);
	fastboot_okay("");
}
#endif
*/

/* register commands and variables for fastboot */
void aboot_fastboot_register_commands(void)
{
	fastboot_register("reboot",            cmd_reboot);
	fastboot_register("reboot-bootloader", cmd_reboot_bootloader);
/*
#if WITH_DEBUG_LOG_BUF
	fastboot_register("oem lk_log",        cmd_oem_lk_log);
#endif
*/
}

void fb_flip(void) {
	struct fbcon_config* fbcon = fbcon_display();
#ifdef PROJECT_MSM8960
	enter_critical_section();
	trigger_mdp_dsi();
	mdelay(10);
	exit_critical_section();
#else
	memcpy(fbcon->base, fb.buf, fb.width*fb.height*fb.bytes_per_pixel);
#endif
}

static int keymap[MAX_KEYS] = {0};
static const unsigned keymap_wait_time = 300;
static unsigned long long keymap_delta = 1000;
static int delivered_key = 0;
int isKeyPressed(int code) {
	int ret = keymap[code];
	if(ret && keymap_delta>=keymap_wait_time) {
		keymap[code] = 0;
		delivered_key = 1;	
		return ret;
	}

	return 0;
}

int isAnyKeyPressed(void) {
	int i, found = 0;

	for(i=0; i<MAX_KEYS; i++) {
		if(keymap[i]) found = 1;
		keymap[i] = 0;
	}

	if(found) delivered_key = 1;

	return found;
}

static unsigned delta = 1000;
static time_t time_last;

extern int target_volume_up(void);
extern uint32_t target_volume_down(void);

static int update_thread(void *arg) {
	time_t t1;
	long wait;

	while(1) {
		// time: now
		time_t now = current_time();

		// update delta
		delta = now - time_last;
		time_last = now;

		// get time for sleep
		t1 = current_time();

		// key check
		keymap_delta+=delta;

		if(keymap_delta>=keymap_wait_time) {
			int up = target_volume_up();
			int down = target_volume_down();

			if(up) keymap[KEY_LEFT] = 1;
			else if(down) keymap[KEY_RIGHT] = 1;
			else if(target_volume_down()) keymap[KEY_UP] = 1;
		}

		// update
		update(delta);

		if(delivered_key) {
			keymap_delta = 0;
			delivered_key = 0;
		}

		// sleep
		wait = (10)-(current_time()-t1);
		if(wait>0)
			thread_sleep(wait);
		else if(wait<0) {
			printf("WARN: update took too long %ld\n", wait);
		}
	}

	return 0;
}

static long wait = 0;
static int render_thread(void *arg) {
	time_t t1;

	while(1) {
		// time: now
		t1 = current_time();

		// render
		render();

		// wait
		wait = (1000/(float)FPS)-(current_time()-t1);
		if(wait>0)
			thread_sleep(wait);
		else if(wait<0) {
			printf("WARN: render took too long %ld\n", wait);
		}
	}

	return 0;
}

long game_get_fps_real(void) {
	return 1000/(1000/FPS-wait);
}

long game_get_fps_limited(void) {
	return FPS;
}

void game_init(const struct app_descriptor *app)
{
	struct fbcon_config* fbcon = NULL;

	ASSERT((MEMBASE + MEMSIZE) > MEMBASE);

	/* Display splash screen if enabled */
	dprintf(SPEW, "Display Init: Start\n");
	target_display_init("");
	fbcon = fbcon_display();
	dprintf(SPEW, "Display Init: Done\n");

	/* register aboot specific fastboot commands */
	aboot_fastboot_register_commands();

	/* initialize and start fastboot */
	fastboot_init(target_get_scratch_address(), target_get_max_flash_size());

	dprintf(INFO, "Start Game...\n");
	fb.width = fbcon->width;
	fb.height = fbcon->height;
	fb.bpp = fbcon->bpp;
	fb.bytes_per_pixel = fb.bpp/8;
	fb.pitch = fbcon->stride;
#ifdef PROJECT_MSM8960
	fb.buf = fbcon->base;
#else
	fb.buf = malloc(fb.width*fb.height*fb.bytes_per_pixel);
	memset(fb.buf, 0, fb.width*fb.height*fb.bytes_per_pixel);
#endif
	init(&fb);

	// time now
	time_last = current_time();
	thread_t *thr;

	thr = thread_create(app->name, &update_thread, 0, DEFAULT_PRIORITY, DEFAULT_STACK_SIZE);
	if(!thr)
	{
		return;
	}
	thread_resume(thr);

	thr = thread_create(app->name, &render_thread, 0, DEFAULT_PRIORITY, DEFAULT_STACK_SIZE);
	if(!thr)
	{
		return;
	}
	thread_resume(thr);
}

APP_START(game)
	.init = game_init,
APP_END
