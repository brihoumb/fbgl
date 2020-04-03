#include <stdlib.h>
#include <signal.h>

#include "../include/init.h"
#include "../include/shape.h"
#include "../include/screen.h"
#include "../include/destroy.h"

static char stop = 1;

void hammerTime()
{
  stop = 0;
}

int main()
{
  framebuffer_t *fb = malloc(sizeof(framebuffer_t));
  void *oldHandler = signal(SIGINT, hammerTime);

  if (fb == NULL)
    return (1);
  init(fb);
  draw_pixel(fb, (fb_vector2ui){10, 10}, RED);
  //draw_fill_rectangle(fb, (fb_vector2ui){4, 4}, (fb_vector2ui){256, 256}, (fb_color){255, 255, 255, 255});
  //draw_fill_rectangle(fb, (fb_vector2ui){256, 256}, (fb_vector2ui){256, 256}, (fb_color){255, 255, 255, 255});
  //draw_fill_circle(fb, (fb_vector2ui){128, 128}, 100, GREEN);
  //draw_empty_circle(fb, (fb_vector2ui){256, 256}, 100, GREEN);
  while (stop) {}
  signal(SIGINT, /*(sighandler_t)*/oldHandler);
  clear_screen(fb, BLACK);
  destroy(fb);
  return (0);
}
