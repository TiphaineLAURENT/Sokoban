/*
** box_move.c for box_move.c in /home/TiphaineLaurent/delivery/sokobanV3
**
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
**
** Started on  Tue Dec 20 21:41:45 2016 Tiphaine LAURENT
** Last update Tue Dec 20 22:39:48 2016 Tiphaine LAURENT
*/

#include "my.h"

t_map		**box_left(t_map **map, int y, int x)
{
  map[y][x - 1].obj2 = FREE;
  map[y][x - 2].obj2 = BOX;
  mvprintw(y, x - 1, "%c", FREE);
  mvprintw(y, x - 2, "X");
  return (map);
}

t_map		**box_right(t_map **map, int y, int x)
{
  map[y][x + 1].obj2 = FREE;
  map[y][x + 2].obj2 = BOX;
  mvprintw(y, x + 1, " ");
  mvprintw(y, x + 2, "X");
  return (map);
}

t_map		**box_up(t_map **map, int y, int x)
{
  map[y - 1][x].obj2 = FREE;
  map[y - 2][x].obj2 = BOX;
  mvprintw(y - 1, x, " ");
  mvprintw(y - 2, x, "X");
  return (map);
}

t_map		**box_down(t_map **map, int y, int x)
{
  map[y + 1][x].obj2 = FREE;
  map[y + 2][x].obj2 = BOX;
  mvprintw(y + 1, x, " ");
  mvprintw(y + 2, x, "X");
  return (map);
}
