/*
** get_map.c for get_map in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
**
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
**
** Started on  Mon Dec 19 23:46:00 2016 Tiphaine LAURENT
** Last update Thu Dec 22 23:59:39 2016 Tiphaine LAURENT
*/

#include "my.h"

int		get_linelen(char *buffer)
{
  int		length;

  length = 0;
  while (buffer[length])
    length += 1;
  return (length);
}

t_map		**stock_map(char *buffer, int size)
{
  t_map		**map;
  int		y;
  int		x;

  y = 0;
  x = 0;
  map = malloc(sizeof(t_map) * size);
  size = get_linelen(buffer);
  map[y] = malloc(sizeof(t_map) * size);
  while (*buffer)
    {
      if (*buffer == '\n')
	{
	  x = 0;
	  y += 1;
	  buffer += 1;
	  size = get_linelen(buffer);
	  map[y] = malloc(sizeof(t_map) * size);
	}
      if (*buffer == PLAYER || *buffer == BOX)
	map[y][x].obj2 = *buffer;
      else
	map[y][x].obj = *buffer;
      x += 1;
      buffer += 1;
    }
  return (map);
}

int		is_ok(char c, t_check *check, int i)
{
  if (i == 0)
    {
      check->p = 0;
      check->x = 0;
      check->o = 0;
    }
  if (c == PLAYER)
    check->p += 1;
  if (c == BOX)
    check->x += 1;
  if (c == OBJECTIF)
    check->o += 1;
  if (check->p == 1 && check->x == check->o)
    return (1);
  else if (check->p > 0 && check->x != check->o)
    return (-1);
  else if (check->p > 1)
    return (-1);
  else
    return (0);
}

t_map	       	**get_map(char *path, t_term *term_d)
{
  struct stat	file_d;
  int		file;
  char		*buffer;
  t_check	check;
  int		i;
  int		error;

  stat(path, &file_d);
  if (!S_ISREG(file_d.st_mode))
    end_screen(84, term_d, "The file you are trying to read is not a map");
  if (!(file = open(path, O_RDONLY)))
    end_screen(84, term_d, "Error while opening the map");
  if (!(buffer = malloc(sizeof(char) * file_d.st_size)))
    end_screen(84, term_d, "Memory error");
  error = read(file, buffer, file_d.st_size);
  i = 0;
  while (buffer[i])
    {
      error = is_ok(buffer[i], &check, i);
      i += 1;
    }
  if (error == -1)
    end_screen(84, term_d, "Map error : reading or incomplete map");
  close(file);
  return (stock_map(buffer, file_d.st_size));
}
