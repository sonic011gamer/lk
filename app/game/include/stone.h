#ifndef __APP_STONE_H
#define __APP_STONE_H

#include <common.h>

#define STONE_WIDTH 4
#define STONE_HEIGHT 4
#define NUM_STONES 7

typedef int stone[STONE_HEIGHT][STONE_WIDTH];

struct stone {
	stone data;
	unsigned diameter;
	unsigned offset_x;
	unsigned offset_y;
	unsigned color;
};

extern int stone_posx;
extern int stone_posy;

void newStone(struct fbconfig* fb);
void drawStone(struct fbconfig* fb);
void copyStone2Map(void);
int stoneOverlaps(stone *data, int diameter, int offset_x, int offset_y);

int stoneCanDown(void);
int stoneCanLeft(void);
int stoneCanRight(void);

void stoneDoRotate(void);
#endif
