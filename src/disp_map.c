/*
** disp_map.c for disp_map in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Tue Dec 20 12:55:14 2016 Tiphaine LAURENT
** Last update Tue Dec 27 14:51:10 2016 Tiphaine LAURENT
*/

#include "my.h"

int		disp_map(t_map **map, t_term *term_d)
{
  int		y;
  int		x;

  clear();
  y = 0;
  x = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x].obj || map[y][x].obj2)
	{
	  /*while (y > term_d->max_y || x > term_d->max_x)
	    {
	      getmaxyx(stdscr, term_d->max_y, term_d->max_x);
	      mvprintw(0, 0, "TEST");
	      }*/
	  mvprintw(y, x, "%c", map[y][x].obj);
	  mvprintw(y, x, "%c", map[y][x].obj2);
	  x += 1;
	}
      y += 1;
    }
  refresh();
  return (0);
}

t_map		**get_and_disp(char *path, t_term *term_d, int restart)
{
  t_map		**map;

  map = get_map(path, term_d);
  disp_map(map, term_d);
  if (restart == 0)
    term_d->start_time = time(NULL);
  return (map);
}
