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
  if (map[pos.y][pos.x - 1].obj2 == BOX)
    {
      if (is_free(map, pos.y, pos.x - 2) == FREE)
	box_left(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y, pos.x - 1) == FREE)
    {
      map[pos.y][pos.x - 1].obj2 = PLAYER;
      map[pos.y][pos.x].obj2 = FREE;
      mvprintw(pos.y, pos.x - 1, "%c", PLAYER);
      mvprintw(pos.y, pos.x, "%c", FREE);
    }
  if (map[pos.y][pos.x].obj == OBJECTIF && map[pos.y][pos.x].obj2 != PLAYER)
	  mvprintw(pos.y, pos.x, "%c", OBJECTIF);
  refresh();
  return (map);
}

t_map		**move_right(t_map **map, t_term *term_d)
{
  t_pos		pos;

  get_pos(map, &pos);
  if (map[pos.y][pos.x + 1].obj2 == BOX)
    {
      if (is_free(map, pos.y, pos.x + 2) == FREE)
	box_right(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y, pos.x + 1) == FREE)
    {
      map[pos.y][pos.x + 1].obj2 = PLAYER;
      map[pos.y][pos.x].obj2 = FREE;
      mvprintw(pos.y, pos.x + 1, "%c", PLAYER);
      mvprintw(pos.y, pos.x, "%c", FREE);
    }
  if (map[pos.y][pos.x].obj == OBJECTIF && map[pos.y][pos.x].obj2 != PLAYER)
	  mvprintw(pos.y, pos.x, "%c", OBJECTIF);
  refresh();
  return (map);
}

t_map		**move_up(t_map **map, t_term *term_d)
{
  t_pos		pos;

  get_pos(map, &pos);
  if (map[pos.y - 1][pos.x].obj2 == BOX)
    {
      if (is_free(map, pos.y - 2, pos.x) == FREE)
	box_up(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y - 1, pos.x) == FREE)
    {
      map[pos.y - 1][pos.x].obj2 = PLAYER;
      map[pos.y][pos.x].obj2 = FREE;
      /* mvprintw(pos.y - 1, pos.x, "%c", PLAYER); */
      attron(COLOR_PAIR(PLAYER_PAIR));
      mvaddch(pos.y - 1, pos.x, PLAYER);
      attroff(COLOR_PAIR(PLAYER_PAIR));
      mvprintw(pos.y, pos.x, "%c", FREE);
    }
  if (map[pos.y][pos.x].obj == OBJECTIF && map[pos.y][pos.x].obj2 != PLAYER)
	  mvprintw(pos.y, pos.x, "%c", OBJECTIF);
  refresh();
  return (map);
}

t_map		**move_down(t_map **map, t_term *term_d)
{
  t_pos		pos;

  get_pos(map, &pos);
  if (map[pos.y + 1][pos.x].obj2 == BOX)
    {
      if (is_free(map, pos.y + 2, pos.x) == FREE)
	box_down(map, pos.y, pos.x);
    }
  if (is_free(map, pos.y + 1, pos.x) == FREE)
    {
      map[pos.y + 1][pos.x].obj2 = PLAYER;
      map[pos.y][pos.x].obj2 = FREE;
      mvprintw(pos.y + 1, pos.x, "%c", PLAYER);
      mvprintw(pos.y, pos.x, "%c", FREE);
    }
  if (map[pos.y][pos.x].obj == OBJECTIF && map[pos.y][pos.x].obj2 != PLAYER)
	  mvprintw(pos.y, pos.x, "%c", OBJECTIF);
  refresh();
  return (map);
}
