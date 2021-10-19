#ifndef __APP_FB_H
#define __APP_FB_H

struct fbconfig {
	unsigned int width;
	unsigned int height;
	unsigned int bpp;
	unsigned int bytes_per_pixel;
	unsigned int pitch;
	void* buf;
	int landscape;
	int grid_w;
	int grid_h;
	int grid_phys_w;
	int grid_phys_h;
};

void fbSetPixelXY(struct fbconfig* fb, unsigned x, unsigned y, unsigned color);
void fbFill(struct fbconfig* fb, unsigned color);
void fbFillRect(struct fbconfig* fb, unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned color);
void fbSetLandscape(struct fbconfig* fb, int enabled);

// grid functions
void fbGridSetSize(struct fbconfig* fb, int width, int height);
void fbGridSetColor(struct fbconfig* fb, int x, int y, int color);

#endif
