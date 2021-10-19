#include <common.h>

// global


// private
static struct fbconfig *fb = NULL;

static void menu_init(struct fbconfig *config) {
	fb = config;
}

static void menu_update(double delta) {
	if(isAnyKeyPressed()) {
		game_state_set_active("ingame", NULL);
	}
}

static void menu_render(void) {
	font_printf_centered(fb, 0, "MENU");
	font_printf_centered(fb, fb->height/2-font_get_height()/2, "> Play <");
}

static struct game_state state = {
	.name = "menu",
	.init = menu_init,
	.update = menu_update,
	.render = menu_render,
};

void state_init_menu(void) {
	game_state_add(&state);
}
