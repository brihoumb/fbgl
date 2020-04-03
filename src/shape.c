#include <stdio.h>

#include "../include/io.h"
#include "../include/pixel.h"

int draw_fill_rectangle(framebuffer_t *framebuffer, fb_vector2ui start_coordinate, fb_vector2ui end_coordinate, fb_color color)
{
  unsigned int x = start_coordinate.x;
  unsigned int y = start_coordinate.y;

  if (framebuffer == NULL)
    return (error("Error: framebuffer not allocated\n"));
  while (y != end_coordinate.y) {
    x = start_coordinate.x;
    while (x != end_coordinate.x) {
      draw_pixel(framebuffer, (fb_vector2ui){x, y}, color);
      x++;
    }
    y++;
  }
  return (0);
}

int draw_empty_rectangle(framebuffer_t *framebuffer, fb_vector2ui start_coordinate, fb_vector2ui end_coordinate, fb_color color)
{
  unsigned int x = start_coordinate.x;
  unsigned int y = start_coordinate.y;

  if (framebuffer == NULL)
    return (error("Error: framebuffer not allocated\n"));
  for (unsigned int i = y; i != end_coordinate.y; i++) {
    draw_pixel(framebuffer, (fb_vector2ui){x, i}, color);
    draw_pixel(framebuffer, (fb_vector2ui){end_coordinate.x, i}, color);
  }
  for (unsigned int i = x; i != end_coordinate.x; i++) {
    draw_pixel(framebuffer, (fb_vector2ui){i, y}, color);
    draw_pixel(framebuffer, (fb_vector2ui){i, end_coordinate.y}, color);
  }
  return (0);
}

void dc(framebuffer_t *fb, fb_color color, unsigned int xc, unsigned int yc, unsigned int x, unsigned int y)
{
  draw_pixel(fb, (fb_vector2ui){xc + x, yc + y}, color);
  draw_pixel(fb, (fb_vector2ui){xc + y, yc + x}, color);
  draw_pixel(fb, (fb_vector2ui){xc - x, yc + y}, color);
  draw_pixel(fb, (fb_vector2ui){xc - y, yc + x}, color);
  draw_pixel(fb, (fb_vector2ui){xc + x, yc - y}, color);
  draw_pixel(fb, (fb_vector2ui){xc + y, yc - x}, color);
  draw_pixel(fb, (fb_vector2ui){xc - x, yc - y}, color);
  draw_pixel(fb, (fb_vector2ui){xc - y, yc - x}, color);
}

int draw_empty_circle(framebuffer_t *framebuffer, fb_vector2ui centre, int radius, fb_color color)
{
  unsigned int x = 0;
  unsigned int y = radius;
  int p = 1 - radius;

  if (framebuffer == NULL)
    return (error("Error: framebuffer not allocated\n"));
  dc(framebuffer, RED, centre.x, centre.y, x, y);
  while (x < y) {
    if (p < 0) {
      x++;
      p = p + 2 * x + 1;
    } else {
      x++;
      y--;
      p = p + 2 * (x - y) + 1;
    }
    dc(framebuffer, YELLOW, centre.x, centre.y, x, y);
  }
  return (0);
}

int draw_fill_circle(framebuffer_t *framebuffer, fb_vector2ui centre, int radius, fb_color color)
{
  return (0);
}
