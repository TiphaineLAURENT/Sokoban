/*
** movement.c for movement.c in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Tue Dec 20 15:06:32 2016 Tiphaine LAURENT
** Last update Tue Dec 20 22:46:58 2016 Tiphaine LAURENT
*/

#include "my.h"

t_map		**move_left(t_map **map, t_term *term_d)
{
  t_pos		pos;

  get_pos(map, &pos);
  if (map[pos.y][pos.x - 1].obj2 == 'X')
    {
      if (is_free(map, pos.y, pos.x - 2) == ' ')
	box_left(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y, pos.x - 1) == ' ')
    {
      map[pos.y][pos.x - 1].obj2 = 'P';
      map[pos.y][pos.x].obj2 = ' ';
      mvprintw(pos.y, pos.x - 1, "P");
      mvprintw(pos.y, pos.x, " ");
    }
  if (map[pos.y][pos.x].obj == 'O' && map[pos.y][pos.x].obj2 != 'P')
    mvprintw(pos.y, pos.x, "O");
  refresh();
  return (map);
}

t_map		**move_right(t_map **map, t_term *term_d)
{
  t_pos		pos;

  get_pos(map, &pos);
  if (map[pos.y][pos.x + 1].obj2 == 'X')
    {
      if (is_free(map, pos.y, pos.x + 2) == ' ')
	box_right(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y, pos.x + 1) == ' ')
    {
      map[pos.y][pos.x + 1].obj2 = 'P';
      map[pos.y][pos.x].obj2 = ' ';
      mvprintw(pos.y, pos.x + 1, "P");
      mvprintw(pos.y, pos.x, " ");
    }
  if (map[pos.y][pos.x].obj == 'O' && map[pos.y][pos.x].obj2 != 'P')
    mvprintw(pos.y, pos.x, "O");
  refresh();
  return (map);
}

t_map		**move_up(t_map **map, t_term *term_d)
{
  t_pos		pos;

  get_pos(map, &pos);
  if (map[pos.y - 1][pos.x].obj2 == 'X')
    {
      if (is_free(map, pos.y - 2, pos.x) == ' ')
	box_up(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y - 1, pos.x) == ' ')
    {
      map[pos.y - 1][pos.x].obj2 = 'P';
      map[pos.y][pos.x].obj2 = ' ';
      mvprintw(pos.y - 1, pos.x, "P");
      mvprintw(pos.y, pos.x, " ");
    }
  if (map[pos.y][pos.x].obj == 'O' && map[pos.y][pos.x].obj2 != 'P')
    mvprintw(pos.y, pos.x, "O");
  refresh();
  return (map);
}

t_map		**move_down(t_map **map, t_term *term_d)
{
  t_pos		pos;

  get_pos(map, &pos);
  if (map[pos.y + 1][pos.x].obj2 == 'X')
    {
      if (is_free(map, pos.y + 2, pos.x) == ' ')
	box_down(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y + 1, pos.x) == ' ')
    {
      map[pos.y + 1][pos.x].obj2 = 'P';
      map[pos.y][pos.x].obj2 = ' ';
      mvprintw(pos.y + 1, pos.x, "P");
      mvprintw(pos.y, pos.x, " ");
    }
  if (map[pos.y][pos.x].obj == 'O' && map[pos.y][pos.x].obj2 != 'P')
    mvprintw(pos.y, pos.x, "O");
  refresh();
  return (map);
}
