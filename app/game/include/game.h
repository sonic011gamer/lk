#ifndef __APP_GAME_H
#define __APP_GAME_H

#include <common.h>

// UI settings
#define COLOR_BORDER 0x4f2606
#define GRID_WIDTH 12
#define GRID_HEIGHT 24
#define MAP_WIDTH GRID_WIDTH-2
#define MAP_HEIGHT GRID_HEIGHT-4
#define MAP_POSX 1
#define MAP_POSY 3

typedef unsigned map_data[MAP_WIDTH][MAP_HEIGHT];
extern map_data map;

void init(struct fbconfig *config);
void update(double delta);
void render(void);

// states
#define MAX_GAME_STATES 8
typedef void (*game_state_init)(struct fbconfig *config);
typedef void (*game_state_update)(double delay);
typedef void (*game_state_render)(void);
typedef void (*game_state_enable)(void* arg);
typedef void (*game_state_disable)(void);

struct game_state {
	const char* name;
	game_state_init init;
	game_state_update update;
	game_state_render render;
	game_state_enable enable;
	game_state_disable disable;
};

int game_state_add(struct game_state *state);
int game_state_set_active(const char* name, void* arg);

#endif
