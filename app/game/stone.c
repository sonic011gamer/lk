#include <common.h>

// global
int stone_posx = 0, stone_posy = 0;

// private
static int stone_initial_posy = 0;

static struct stone stone1 = {
	{
		{0,0,0},
		{1,1,1},
		{1,0,0},
	}, 3, 0, 1, 0xff00ff
};

static struct stone stone2 = {
	{
		{0,0,0,0},
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
	}, 4, 0, 1, 0xff0000
};

static struct stone stone3 = {
	{
		{0,0,0},
		{1,1,1},
		{0,1,0},
	}, 3, 0, 0, 0xffff00
};

static struct stone stone4 = {
	{
		{0,1,1},
		{1,1,0},
	}, 3, 0, 0, 0x00ff00
};

static struct stone stone5 = {
	{
		{1,1,0},
		{0,1,1},
	}, 3, 0, 0, 0x00ffff
};

static struct stone stone6 = {
	{
		{1,1},
		{1,1},
	}, 2, 0, 0, 0x0000ff
};

static struct stone stone7 = {
	{
		{0,0,0},
		{1,1,1},
		{0,0,1},
	}, 3, 0, 1, 0xffffff
};
static struct stone active_stone = {{},0,0,0,0};
static struct stone* stones[NUM_STONES] = {
	&stone1,
	&stone2,
	&stone3,
	&stone4,
	&stone5,
	&stone6,
	&stone7,
};

#if LK
unsigned myRand(unsigned low, unsigned high) {
	unsigned long time;

#if TARGET_MSM8960
	time = readl(GPT_COUNT_VAL);
#else
	time = qtimer_get_phy_timer_cnt();
#endif

	return (time%10) % (high - low + 1) + low;
}
#else
// http://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range
static unsigned getRandomStone(void) {
	unsigned long r, n = NUM_STONES-1+1;
	struct timespec t1;
	clock_gettime(CLOCK_MONOTONIC, &t1);
	srand(t1.tv_nsec);

	r = n / 2;
	r = (rand() * n + r) / (RAND_MAX + 1UL);
	r = (rand() * n + r) / (RAND_MAX + 1UL);
	r = (rand() * n + r) / (RAND_MAX + 1UL);

	return r;
}
#endif

static int stoneGetBottomLine(struct stone* stone) {
	int x,y, height = 0;
	for(y=0; y<(int)stone->diameter; y++) {
		for(x=0; x<(int)stone->diameter; x++) {
			if(active_stone.data[y][x]) {
				height++;
				break;
			}
		}
	}
	return height;
}

void newStone(struct fbconfig* fb) {
	unsigned stone;
#if LK
	stone = myRand(0,6);
#else
	stone = getRandomStone();
#endif

	if(stone>6) {
		printf("ERR: stone=%d\n", stone);
		stone=0;
	}

	active_stone = *stones[stone];
	stone_posx = fb->grid_w/2 - active_stone.diameter/2 - active_stone.offset_x -1;
	stone_posy = 0 - stoneGetBottomLine(&active_stone)-1;
	stone_initial_posy = stone_posy;
}

void drawStone(struct fbconfig* fb) {
	unsigned i,j;

	for(i=0; i<active_stone.diameter; i++) {
		for(j=0; j<active_stone.diameter; j++) {
			if(active_stone.data[i][j]) {
				int x = MAP_POSX+stone_posx+j;
				int y = MAP_POSY+stone_posy+i;

				if(x>=MAP_POSX && y>=MAP_POSY)
					fbGridSetColor(fb, x, y, active_stone.color);
			}
		}
	}
}

void copyStone2Map(void) {
	unsigned i,j;

	for(i=0; i<active_stone.diameter; i++) {
		for(j=0; j<active_stone.diameter; j++) {
			if(active_stone.data[i][j]) {
				int x = j+stone_posx;
				int y = i+stone_posy;

				if(x<0 || y<0)
					continue;

				map[j+stone_posx][i+stone_posy] = active_stone.color;
			}
		}
	}
}

int stoneOverlaps(stone *data, int diameter, int offset_x, int offset_y) {
	int x,y;
	if(data==NULL) {
		data = &active_stone.data;
		diameter = active_stone.diameter;
	}

	for(y=0; y<diameter; y++) {
		for(x=0; x<diameter; x++) {
			if(
				// we have a stone part
				(*data)[y][x]

				&& (
					// position x <0
					(stone_posx+x+offset_x<0)

					// position y < initial drop position
					|| (stone_posy+y+offset_y<stone_initial_posy)

					// position is outside map (right or bottom)
					|| (stone_posx+x+offset_x>=MAP_WIDTH || stone_posy+y+offset_y>=MAP_HEIGHT)

					|| (
						// range check for map
						(stone_posx+x+offset_x>=0)
						&& (stone_posy+y+offset_y>=0)

						// there's another stone on the map
						&& (map[stone_posx+x+offset_x][stone_posy+y+offset_y])
					)
				)
			)
				return 1;
		}
	}
	return 0;
}

int stoneCanDown(void) {
	return !stoneOverlaps(NULL, 0, 0, 1);
}

int stoneCanLeft(void) {
	return !stoneOverlaps(NULL, 0, -1, 0);
}

int stoneCanRight(void) {
	return !stoneOverlaps(NULL, 0, 1, 0);
}

// http://stackoverflow.com/questions/42519/how-do-you-rotate-a-two-dimensional-array
void stoneDoRotate(void) {
	int n=active_stone.diameter;
	int i,j;
	stone local_data;

	// middle
	local_data[n/2][n/2] = 	active_stone.data[n/2][n/2];

	for (i=0; i<n/2; i++) {
		for (j=i; j<n-i-1; j++) {
			local_data[i][j]=active_stone.data[j][n-i-1];
			local_data[j][n-i-1]=active_stone.data[n-i-1][n-j-1];
			local_data[n-i-1][n-j-1]=active_stone.data[n-j-1][i];
			local_data[n-j-1][i]=active_stone.data[i][j];
		}
	}

	// check collision
	if(!stoneOverlaps(&local_data, n, 0, 0)) {
		for(i=0; i<n; i++)
			memcpy(&active_stone.data[i], &local_data[i], sizeof(local_data[0]));
	}
}
