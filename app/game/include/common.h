#ifndef __APP_COMMON_H
#define __APP_COMMON_H

#include <main.h>
#include <game.h>
#include <fb.h>
#include <stone.h>
#include <font.h>

#include <string.h>
#include <stdlib.h>

#if LK
#include <debug.h>
#include <dev/keys.h>
#include <platform.h>

#include <reg.h>
#include <platform/iomap.h>
#include <kernel/mutex.h>
#include <include/qtimer.h>

#define printf _dprintf
#else
#include <stdio.h>
#include <linux/input.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <stdarg.h>

typedef pthread_mutex_t mutex_t;
#define mutex_init(x) pthread_mutex_init(x, NULL)
#define mutex_acquire pthread_mutex_lock
#define mutex_release pthread_mutex_unlock
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
#endif

#ifndef RAND_MAX
#define RAND_MAX INT_MAX
#endif

#define COORD_TO_INDEX(x,y,width) (y*width + x)

#endif
