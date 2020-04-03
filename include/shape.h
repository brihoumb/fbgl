/*
** EPITECH PROJECT, 2019
** fblib
** File description:
** shapes
*/

#ifndef FRAMEBUFFER_SHAPE_H_
#define FRAMEBUFFER_SHAPE_H_

#include "color.h"
#include "vector.h"
#include "framebuffer.h"

int draw_fill_circle(framebuffer_t*, fb_vector2ui, int, fb_color);
int draw_empty_circle(framebuffer_t*, fb_vector2ui, int, fb_color);
int draw_fill_rectangle(framebuffer_t*, fb_vector2ui, fb_vector2ui, fb_color);
int draw_empty_rectangle(framebuffer_t*, fb_vector2ui, fb_vector2ui, fb_color);

#endif /* FRAMEBUFFER_SHAPE_H_ */
