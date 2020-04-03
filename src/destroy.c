/*
** EPITECH PROJECT, 2019
** fblib
** File description:
** destructor
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#include "../include/framebuffer.h"

int destroy(framebuffer_t *framebuffer)
{
  if (munmap(framebuffer->framebuffer_page, framebuffer->screensize) ||
      close(framebuffer->frameid)) {
    free(framebuffer);
    return (1);
  }
  free(framebuffer);
  return 0;
}
