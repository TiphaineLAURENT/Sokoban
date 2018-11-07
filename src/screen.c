/*
** screen.c for screen in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
**
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
**
** Started on  Mon Dec 19 22:58:30 2016 Tiphaine LAURENT
** Last update Thu Dec 22 18:27:39 2016 Tiphaine LAURENT
*/

#include "my.h"

static void init_colors(void)
{
	start_color();
	/* init_pair(1, COLOR_WHITE, COLOR_BLACK); */
	init_pair(PLAYER_PAIR, COLOR_RED, COLOR_BLACK);
}

int		init_screen(t_term *term_d)
{
  WINDOW	*win;

  win = initscr();
  raw();
  noecho();
  curs_set(FALSE);
  nodelay(win, TRUE);
  keypad(stdscr, TRUE);
  init_colors();
  getmaxyx(stdscr, term_d->max_y, term_d->max_x);
  term_d->start_time = time(NULL);
  return (0);
}

int		end_screen(int to_do, t_term *term_d, char *message)
{
  my_popup(term_d, message);
  usleep(3000000);
  if (to_do >= 84 || to_do == 2)
    {
      endwin();
      exit(to_do);
    }
  return (to_do);
}
