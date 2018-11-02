/*
** path.c for path in /home/TiphaineLaurent/delivery/sokobanV3
**
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
**
** Started on  Thu Dec 22 16:39:57 2016 Tiphaine LAURENT
** Last update Thu Dec 22 23:37:28 2016 Tiphaine LAURENT
*/

#include <stdio.h>
#include "my.h"

char		*create_path(char *name, t_term *term_d)
{
  char		*path;
  int		i;

  path = malloc(sizeof(char) * (7 + my_strlen(name)) + 1);
  if (path == NULL)
    end_screen(84, term_d, "Error while retriving map path");
  path[0] = 'm';
  path[1] = 'a';
  path[2] = 'p';
  path[3] = 's';
  path[4] = '/';
  i = 5;
  while (*name)
    {
      path[i] = *name;
      name += 1;
      i += 1;
    }
  path[i] = 0;
  return (path);
}
