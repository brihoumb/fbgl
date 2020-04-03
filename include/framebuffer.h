/*
** EPITECH PROJECT, 2019
** fblib
** File description:
** framebuffer structure
*/

#ifndef FRAMEBUFFER_STRUCT_H_
#define FRAMEBUFFER_STRUCT_H_

#include <linux/fb.h>

typedef int fd_t;
typedef void *map;
typedef struct framebuffer_s framebuffer_t;

struct framebuffer_s {
    fd_t frameid;
    long int screensize;
    map framebuffer_page;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
};

#endif /* FRAMEBUFFER_STRUCT_H_*/
