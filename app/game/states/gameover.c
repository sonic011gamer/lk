#include <common.h>

// global


// private
static struct fbconfig *fb = NULL;
static unsigned long long score = 0;
static double local_time = 0;

static void gameover_init(struct fbconfig *config) {
	fb = config;
}

static void gameover_update(double delta) {
	local_time+=delta;

	// prevent treating ingame input as input for this state
	if(local_time<1000) return;

	if(isAnyKeyPressed()) {
		game_state_set_active("menu", NULL);
	}
}

static void gameover_render(void) {
	font_printf_centered(fb, 0, "GAME OVER");
	font_printf_centered(fb, fb->height/2-font_get_height()/2-font_get_height(), "Your Score:");
	font_printf_centered(fb, fb->height/2-font_get_height()/2+font_get_height(), "%lld", score);
}

void gameover_enable(void* arg) {
	score = *((unsigned long long*)arg);
	local_time = 0;
}

static struct game_state state = {
	.name = "gameover",
	.init = gameover_init,
	.update = gameover_update,
	.render = gameover_render,
	.enable = gameover_enable,
};

void state_init_gameover(void) {
	game_state_add(&state);
}
