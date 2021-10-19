#ifndef SPLASH_H
#define SPLASH_H

#include <dev/fbcon.h>

int splash_screen_check_header(logo_img_header *header);
int splash_screen_flash();
int splash_screen_mmc();
int fetch_image_from_partition();

#endif // SPLASH_H
