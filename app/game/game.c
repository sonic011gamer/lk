#include <common.h>

// global
extern void state_init_ingame(void);
extern void state_init_menu(void);
extern void state_init_gameover(void);

// private
static struct fbconfig *fb = NULL;
static struct game_state states[MAX_GAME_STATES];
static int num_states = 0;
static int active_state = -1;
static mutex_t render_lock;

int game_state_add(struct game_state *state) {
	if(state==NULL) return 1;
	if(num_states==MAX_GAME_STATES) return 1;

	states[num_states++] = *state;

	return 0;
}

static int game_state_get_by_name(const char* name) {
	int i;
	for(i=1; i<=num_states; i++) {
		if(strcmp(states[i-1].name, name)==0)
			return i-1;
	}

	return -1;
}

int game_state_set_active(const char* name, void* arg) {
	int state = game_state_get_by_name(name);
	if(state>=0 && state <num_states) {
		mutex_acquire(&render_lock);

		if(active_state>=0 && states[active_state].disable)
			states[active_state].disable();

		if(states[state].enable)
			states[state].enable(arg);

		active_state = state;

		states[active_state].init(fb);

		mutex_release(&render_lock);
		return 0;
	}

	return 1;
}

void init(struct fbconfig *config) {
	fb = config;
	mutex_init(&render_lock);

	state_init_ingame();
	state_init_menu();
	state_init_gameover();
	game_state_set_active("menu", NULL);

	font_init();

	if(active_state>=0)
		states[active_state].init(config);
}

void update(double delta) {
	states[active_state].update(delta);
}

void render(void) {
	mutex_acquire(&render_lock);

	// clear
	memset(fb->buf, 0x0, fb->width*fb->height*fb->bpp/8);

	if(active_state>=0)
		states[active_state].render();

	// flip
	fb_flip();

	mutex_release(&render_lock);
}
