#ifndef __APP_FONT_H
#define __APP_FONT_H

void font_init(void);
void font_putc(struct fbconfig* fb, char c, unsigned fb_x, unsigned fb_y);
void font_puts(struct fbconfig* fb, const char* str, unsigned fb_x, unsigned fb_y);
int font_printf(struct fbconfig* fb, unsigned fb_x, unsigned fb_y, const char *fmt, ...);
int font_printf_centered(struct fbconfig* fb, unsigned fb_y, const char *fmt, ...);

int font_get_height(void);
int font_get_str_width(const char* str);

#endif
