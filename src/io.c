/*
** EPITECH PROJECT, 2019
** fblib
** File description:
** io
*/

#include <unistd.h>

int length(char *str)
{
  int i = 0;

  while (i[str])
    i++;
  return (i);
}

int error(char *msg)
{
  write(2, msg, length(msg));
  return (1);
}
