#ifndef __APP_MAIN_H
#define __APP_MAIN_H

#include <fb.h>

void fb_flip(void);
long game_get_fps_real(void);
long game_get_fps_limited(void);
int isKeyPressed(int code);
int isAnyKeyPressed(void);

#endif
