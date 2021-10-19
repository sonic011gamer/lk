#include <common.h>

// global
map_data map = {{}};

// private
static struct fbconfig *fb = NULL;
static mutex_t map_lock;
static unsigned long long level;
static unsigned long long lines;
static unsigned long long score;

static void fallDown(int index) {
	unsigned x,y;

	for(y=index; y>0; y--) {
		if(y==0) {
			for(x=0; x<MAP_WIDTH; x++)
				map[x][y] = 0;
		}
		else {
			for(x=0; x<MAP_WIDTH; x++)
				map[x][y] = map[x][y-1];
		}
	}
}

static void tryClearMap(void) {
	static int last_was_tetris = 0;
	unsigned i,j;
	unsigned local_lines = 0;

	for(i=0; i<MAP_HEIGHT; i++) {
		int num=0;
		for(j=0; j<MAP_WIDTH; j++) {
			if(map[j][i]) num++;
			else break;
		}

		if(num==MAP_WIDTH) {
			fallDown(i);
			local_lines++;
		}
	}

	// add to global lines
	lines+=local_lines;

	if(local_lines>=4) {
		// back-to-back tetris
		if(last_was_tetris) score+=1200;
		// single tetris
		else score+=800;

		last_was_tetris = 1;
		local_lines-=4;

		// give 100 for the others
		while(local_lines--)
			score+=100;
	}
	else if(local_lines>0) {
		last_was_tetris = 0;
		
		// give 100 per line
		while(local_lines--)
			score+=100;
	}

	level = 1 + score / 10000;
}

static void ingame_init(struct fbconfig *config) {
	fb = config;
	fbGridSetSize(fb, GRID_WIDTH, GRID_HEIGHT);

	newStone(fb);
	mutex_init(&map_lock);
}

static void ingame_update(double delta) {
	static unsigned time = 0, mod, c;
	unsigned time_stone_drop = 500 - (400/10)*(level-1);
	time+=(unsigned)delta;

	// input
	if(isKeyPressed(KEY_RIGHT) && stoneCanRight())
		stone_posx++;
	if(isKeyPressed(KEY_LEFT) && stoneCanLeft())
		stone_posx--;
	if(isKeyPressed(KEY_DOWN) && stoneCanDown())
		stone_posy++;
	if(isKeyPressed(KEY_UP))
		stoneDoRotate();

	// auto fall
	mod = time % time_stone_drop;
	c = time / time_stone_drop;
	if(c>0) {
		time = mod;
		mutex_acquire(&map_lock);
		if(!stoneCanDown()) {
			// bottom reached

			copyStone2Map();
			tryClearMap();

			newStone(fb);
			if(stoneOverlaps(NULL, 0, 0, 1)) {
				game_state_set_active("gameover", &score);
			}
		}
		else stone_posy+=c;

		mutex_release(&map_lock);
	}

}

static void ingame_render(void) {
	int i,j;

	// border
	for(i=MAP_POSX; i<=MAP_WIDTH+MAP_POSX; i++) {
		fbGridSetColor(fb, i, fb->grid_h-1, COLOR_BORDER);
	}
	for(i=MAP_POSY; i<=MAP_HEIGHT+MAP_POSY; i++) {
		fbGridSetColor(fb, 0, i, COLOR_BORDER);
		fbGridSetColor(fb, fb->grid_w-1, i, COLOR_BORDER);
	}

	mutex_acquire(&map_lock);

	// map
	for(i=0; i<MAP_HEIGHT; i++) {
		for(j=0; j<MAP_WIDTH; j++) {
			if(map[j][i]) {
				fbGridSetColor(fb, j+MAP_POSX, i+MAP_POSY, map[j][i]);
			}
		}
	}

	// active stone
	drawStone(fb);

	font_printf(fb, 0, 0, "Level: %llu", level);
	font_printf(fb, 0, font_get_height(), "Lines: %llu", lines);
	font_printf(fb, 0, font_get_height()*2, "Score: %llu", score);

	mutex_release(&map_lock);
}

void ingame_enable(void* arg) {
	level = 1;
	lines = 0;
	score = 0;
	memset(map, 0, sizeof(map_data));
}

static struct game_state state = {
	.name = "ingame",
	.init = ingame_init,
	.update = ingame_update,
	.render = ingame_render,
	.enable = ingame_enable,
};

void state_init_ingame(void) {
	game_state_add(&state);
}
