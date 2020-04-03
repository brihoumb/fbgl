/*
** EPITECH PROJECT, 2019
** fblib
** File description:
** init
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include "../include/io.h"
#include "../include/framebuffer.h"

int roundUp(float x, float y)
{
  int ires = x / y;
  float fres = x / y;

  if (fres < (float)ires)
    return (ires);
  else if (fres > (float)ires)
    return (ires + 1);
  else
    return (ires);
}

int init(framebuffer_t *framebuffer)
{
  const int page = sysconf(_SC_PAGE_SIZE);

  if (framebuffer == NULL)
    return (error("Error: framebuffer not allocated\n"));
  framebuffer->frameid = open("/dev/fb0", O_RDWR);
  if (framebuffer->frameid == -1)
    return (error("Error: cannot open framebuffer device\n"));
  if (ioctl(framebuffer->frameid, FBIOGET_FSCREENINFO, &framebuffer->finfo) == -1)
    return (error("Error reading fixed information\n"));
  if (ioctl(framebuffer->frameid, FBIOGET_VSCREENINFO, &framebuffer->vinfo) == -1)
    return (error("Error reading variable information\n"));
  framebuffer->screensize = framebuffer->vinfo.xres * framebuffer->vinfo.yres * framebuffer->vinfo.bits_per_pixel / 8;
  framebuffer->screensize = page * roundUp(framebuffer->screensize, page);
  framebuffer->framebuffer_page = mmap(0, framebuffer->screensize, PROT_READ | PROT_WRITE, MAP_SHARED, framebuffer->frameid, 0);
  if (framebuffer->framebuffer_page == MAP_FAILED)
    return (error("Error: failed to map framebuffer device to memory\n"));
  framebuffer->framebuffer_page = memset(framebuffer->framebuffer_page, 0, framebuffer->screensize);
  return (0);
}
