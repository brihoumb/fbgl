#include "../include/io.h"
#include "../include/pixel.h"
#include "../include/vector.h"

#ifndef NULL
#define NULL (void*)0
#endif

int clear_screen(framebuffer_t *framebuffer, fb_color color)
{
  unsigned int x = 0;
  unsigned int y = 0;

  if (framebuffer == NULL)
    return (error("Error: framebuffer not allocated\n"));
  while (y != framebuffer->vinfo.yres) {
    x = 0;
    while (x != framebuffer->vinfo.xres) {
      draw_pixel(framebuffer, (fb_vector2ui){x, y}, color);
      x++;
    }
    y++;
  }
  return (0);
}
