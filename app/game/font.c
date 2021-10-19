#include <common.h>
#if LK
#include <fonts/font_sans_40.h>
#else
#include <fonts/font_sans_25.h>
#endif

#define PIXEL_TO_COLOR(p) (p[0]<<16|p[1]<<8|p[2])

static char* font = NULL;

static unsigned fontGetPixel(unsigned index) {
	short r,g,b;
	unsigned first = index * 3;

	if(index>=font_width*font_height) {
		return 0;
	}

	r = font[first];
	g = font[first+1];
	b = font[first+2];

	return r<<16|g<<8|b;
}

void font_init(void) {
	unsigned i;
	char* pixel;
	char* data = header_data;

	font = pixel =  (char*) calloc(font_width*font_height*3 + 1, sizeof(char));
	if(font==NULL) {
		printf("ERROR reserving space for font!\n");
		return;
	}

	i = font_width * font_height;
	while(i-- > 0) {
		HEADER_PIXEL(data, pixel);
		pixel+=3;
	}
}

static unsigned fontGetPixelXY(unsigned x, unsigned y) {
	return fontGetPixel(COORD_TO_INDEX(x,y, font_width));
}

void font_putc(struct fbconfig* fb, char c, unsigned fb_x, unsigned fb_y) {
	unsigned x,y,tmpx;

	if(!font) return;

	c-=32;
	if(c>=96) {
		printf("invalid char\n");
		return;
	}

	for(y=0; y<font_height; y++) {
		tmpx = fb_x;
		for(x=0; x<font_height; x++) {
			unsigned color = fontGetPixelXY(c*font_height+x, y);
			if(color) fbSetPixelXY(fb, tmpx, fb_y, color);
			tmpx++;
		}
		fb_y++;
	}
}

void font_puts(struct fbconfig* fb, const char* str, unsigned fb_x, unsigned fb_y) {
	while(*str != 0) {
		font_putc(fb, *str++, fb_x, fb_y);
		fb_x+=font_height;
	}
}

int font_printf(struct fbconfig* fb, unsigned fb_x, unsigned fb_y, const char *fmt, ...) {
	char buf[256];
	int err;

	va_list ap;
	va_start(ap, fmt);
	err = vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);

	font_puts(fb, buf, fb_x, fb_y);

	return err;
}

int font_printf_centered(struct fbconfig* fb, unsigned fb_y, const char *fmt, ...) {
	char buf[256];
	int err;

	va_list ap;
	va_start(ap, fmt);
	err = vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);

	font_puts(fb, buf, fb->width/2-font_get_str_width(buf)/2, fb_y);

	return err;
}

int font_get_height(void) {
	return font_height;
}

int font_get_str_width(const char* str) {
	return (strlen(str)*font_get_height());
}
