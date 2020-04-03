#include "../include/io.h"
#include "../include/color.h"
#include "../include/vector.h"
#include "../include/framebuffer.h"

#ifndef NULL
# define NULL ((void *)0)
#endif

int draw_pixel(framebuffer_t *framebuffer, fb_vector2ui coordinate, fb_color color)
{
  long int framebuffer_write_index = 0;

  if (framebuffer == NULL)
    return (error("Error: framebuffer not allocated\n"));
  framebuffer_write_index = (coordinate.x + framebuffer->vinfo.xoffset) *
    (framebuffer->vinfo.bits_per_pixel / 8) +
    (coordinate.y + framebuffer->vinfo.yoffset) *
    framebuffer->finfo.line_length;
  *(char*)(framebuffer->framebuffer_page + framebuffer_write_index) = color.b;
  *(char*)(framebuffer->framebuffer_page + framebuffer_write_index + 1) = color.g;
  *(char*)(framebuffer->framebuffer_page + framebuffer_write_index + 2) = color.r;
  *(char*)(framebuffer->framebuffer_page + framebuffer_write_index + 3) = color.a;
  return (0);
}
