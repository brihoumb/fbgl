#ifndef FRAMEBUFFER_COLOR_H_
#define FRAMEBUFFER_COLOR_H_

typedef struct color fb_color;

struct color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

#ifndef FAMEBUFFER_8BIT_COLOR_D_
#define FAMEBUFFER_8BIT_COLOR_D_

#define RED	(fb_color){255, 000, 000, 255}
#define BLUE	(fb_color){000, 000, 255, 255}
#define CYAN	(fb_color){000, 255, 255, 255}
#define BLACK	(fb_color){000, 000, 000, 255}
#define GREEN	(fb_color){000, 255, 000, 255}
#define WHITE	(fb_color){255, 255, 255, 255}
#define YELLOW	(fb_color){255, 255, 000, 255}
#define MAGENTA	(fb_color){255, 000, 255, 255}

#endif /* FAMEBUFFER_8BIT_COLOR_D_ */

#endif /*F RAMEBUFFER_COLOR_H_ */
