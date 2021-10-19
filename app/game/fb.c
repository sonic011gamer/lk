#include <common.h>

/*
 * ===================================================================================
 * COMMON
 * ===================================================================================
 */

static void fbSetPixel(struct fbconfig* fb, unsigned index, unsigned color) {
	short r,g,b;
	char* buf = (char*) fb->buf;
	unsigned first = index * fb->bytes_per_pixel;

	if(index>=fb->width*fb->height)
		return;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF) >> 0;

#ifdef PROJECT_MSM8960
	buf[first] = r;
	buf[first+1] = g;
	buf[first+2] = b;
#else
	// our framebuffers use BGR
	buf[first] = b;
	buf[first+1] = g;
	buf[first+2] = r;
#endif
}

void fbSetPixelXY(struct fbconfig* fb, unsigned x, unsigned  y, unsigned color) {
	unsigned width = fb->width;
	if(fb->landscape) {
		unsigned tmp = x;
		width = fb->height;

		x = fb->height-1 - y;
		y = tmp;
	}
	fbSetPixel(fb, COORD_TO_INDEX(x,y, width), color);
}

void fbFill(struct fbconfig* fb, unsigned color) {
	unsigned i;

	for(i=0; i<fb->width*fb->height; i++)
		fbSetPixel(fb, i, color);
}

void fbFillRect(struct fbconfig* fb, unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned color) {
	unsigned x, y;

	for(x=x1; x<x2; x++) {
		for(y=y1; y<y2; y++) {
			fbSetPixelXY(fb, x, y, color);
		}
	}
}

void fbSetLandscape(struct fbconfig* fb, int enabled) {
	unsigned tmp = fb->width;
	fb->width = fb->height;
	fb->height = tmp;
	fb->landscape = !fb->landscape;
}

/*
 * ===================================================================================
 * GRID
 * ===================================================================================
 */

void fbGridSetSize(struct fbconfig* fb, int width, int height) {
	fb->grid_phys_w = fb->width/width;
	fb->grid_phys_h = fb->height/height;
	fb->grid_w = width;
	fb->grid_h = height;
}
static const int SIDE_TOP = 1;
static const int SIDE_RIGHT = 2;
static const int SIDE_BOTTOM = 4;
static const int SIDE_LEFT = 8;

static void fbGridBorder(struct fbconfig* fb, int x, int y, int color, int sides, int offset, int radius) {
	int x_real = x*fb->grid_phys_w+offset;
	int y_real = y*fb->grid_phys_h+offset;
	int width = fb->grid_phys_w-offset*2;
	int height = fb->grid_phys_h-offset*2;

	// top
	if(sides & SIDE_TOP)
		fbFillRect(fb, x_real, y_real, x_real+width, y_real+radius, color);
	// bottom
	if(sides & SIDE_BOTTOM)
		fbFillRect(fb, x_real, y_real+height-radius, x_real+width, y_real+height, color);
	// left
	if(sides & SIDE_LEFT)
		fbFillRect(fb, x_real, y_real, x_real+radius, y_real+height, color);
	// right
	if(sides & SIDE_RIGHT)
		fbFillRect(fb, x_real+width-radius, y_real, x_real+width, y_real+height, color);
}

static float min(float x, float y) {
	return ( x > y ) ? y : x;
}
static float max(float x, float y) {
	return ( x > y ) ? x : y;
}

static int changeBrightness(int color, double change) {
	short r,g,b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF) >> 0;

	r = max(0, min(255, r+change));
	g = max(0, min(255, g+change));
	b = max(0, min(255, b+change));

	return r<<16|g<<8|b;
}


void fbGridSetColor(struct fbconfig* fb, int x, int y, int color) {
	int x_real = x*fb->grid_phys_w;
	int y_real = y*fb->grid_phys_h;

	if(x<0 || y<0) return;

	fbFillRect(fb, x_real, y_real, x_real+fb->grid_phys_w, y_real+fb->grid_phys_h, color);

	// black border
	fbGridBorder(fb, x, y, 0x000000, SIDE_TOP|SIDE_RIGHT|SIDE_BOTTOM|SIDE_LEFT, 0, 1);

	// 3d effect
	fbGridBorder(fb, x, y, changeBrightness(color, -100), SIDE_BOTTOM|SIDE_LEFT, 1, 2);
	fbGridBorder(fb, x, y, changeBrightness(color, 100), SIDE_TOP|SIDE_RIGHT, 1, 2);
}
