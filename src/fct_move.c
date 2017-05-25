/*
** fct_move.c for fct_move in /home/TiphaineLaurent/delivery/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Tue Dec 20 15:42:26 2016 Tiphaine LAURENT
** Last update Tue Dec 20 20:04:15 2016 Tiphaine LAURENT
*/

#include "my.h"

t_pos		*get_pos(t_map **map, t_pos *pos)
{
  int		y;
  int		x;

  y = 0;
  x = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x].obj || map[y][x].obj2)
	{
	  if (map[y][x].obj2 == 'P')
	    {
	      pos->y = y;
	      pos->x = x;
	      return (pos);
	    }
	  x += 1;
	}
      y += 1;
    }
  pos = NULL;
  return (pos);
}

int		is_free(t_map **map, int y, int x)
{
  if (map[y][x].obj == 'X' || map[y][x].obj2 == 'X')
    return ('X');
  if (map[y][x].obj == 'O')
    return (' ');
  if (map[y][x].obj == '#')
    return ('#');
  return (' ');
}
