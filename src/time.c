/*
** time.c for time in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Tue Dec 20 14:56:09 2016 Tiphaine LAURENT
** Last update Thu Dec 22 21:45:35 2016 Tiphaine LAURENT
*/

#include "my.h"

int		timer(t_time *time_save, t_term *term_d)
{
  time_save->game_time = time(NULL);
  time_save->delta = time_save->game_time - term_d->start_time;
  mvprintw(term_d->max_y / 3, term_d->max_x / 4, "Time : %d", time_save->delta);
  refresh();
  if (time_save->delta == 30)
    return (0);
  else
    return (30 - time_save->delta);
}

int		timer_pause(t_time *time_save, t_term *term_d)
{
  int		key;

  while ((key = getch()) != 112)
    {
      time_save->game_time = time(NULL);
      term_d->start_time += time_save->game_time - term_d->start_time - time_save->delta;
    }
  return (0);
}
