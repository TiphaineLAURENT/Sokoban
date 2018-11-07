/*
** check_map.c for check_map in /home/TiphaineLaurent/delivery/sokobanV3
**
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
**
** Started on  Thu Dec 22 13:46:02 2016 Tiphaine LAURENT
** Last update Fri Dec 23 00:30:24 2016 Tiphaine LAURENT
*/

#include "my.h"

int		is_loose(t_map **map, int y, int x, t_term *term_d)
{
  int		wall;

  wall = 0;
  if (map[y][x - 1].obj == WALL || map[y][x - 1].obj2 == BOX)
    wall += 1;
  if (map[y][x + 1].obj == WALL || map[y][x + 1].obj2 == BOX)
    wall += 1;
  if (map[y - 1][x].obj == WALL || map[y - 1][x].obj2 == BOX)
    wall += 1;
  if (map[y + 1][x].obj == WALL ||map[y + 1][x].obj2 == BOX)
    wall += 1;
  if (wall > 1)
    return (end_screen(1, term_d, "YOU LOST !"));
  return (wall);
}

int		check_map(t_map **map, t_term *term_d)
{
  int		y;
  int		x;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x].obj || map[y][x].obj2)
	{
	  if ((map[y][x].obj == OBJECTIF && map[y][x].obj2 != BOX)
	      || (map[y][x].obj != OBJECTIF && map[y][x].obj2 == BOX))
	    return (0);
	  if (map[y][x].obj2 == BOX && map[y][x].obj != OBJECTIF)
	    is_loose(map, y, x, term_d);
	  x += 1;
	}
      y += 1;
    }
  return (1);
}
