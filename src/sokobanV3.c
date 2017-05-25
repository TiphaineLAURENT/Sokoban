/*
** sokobanV3.c for sokobanV3 in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Mon Dec 19 22:47:09 2016 Tiphaine LAURENT
** Last update Tue Dec 27 14:51:26 2016 Tiphaine LAURENT
*/

#include "my.h"

static	t_move	g_move[] =
  {
    {258, &move_down},
    {259, &move_up},
    {260, &move_left},
    {261, &move_right},
    {115, &move_down},
    {122, &move_up},
    {113, &move_left},
    {100, &move_right},
    {0, NULL}
  };

int		key()
{
  int		key;

  initscr();
  raw();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  key = 0;
  while (key != 360)
    {
      key = getch();
      clear();
      printw("%c = %d\n", (char) key, key);
      refresh();
    }
  endwin();
  return (0);
}

int		game(char *path, t_term *term_d)
{
  int		key;
  int		i;
  t_time	time_save;
  t_map		**map;

  map = get_and_disp(path, term_d, 0);
  while ((key = getch()) != 360)
    {
      if (key == 32)
	map = get_and_disp(path, term_d, 1);
      if (key == 112)
	timer_pause(&time_save, term_d);
      if (timer(&time_save, term_d) == 0)
	return (end_screen(0, term_d, "GAME OVER"));
      i = 0;
      while (g_move[i].key)
	{
	  if (g_move[i].key == key)
	    g_move[i].moves(map, term_d);
	  i += 1;
	}
      if (check_map(map, term_d))
	return (end_screen(time_save.delta, term_d, "YOU WON !"));
    }
  return (0);
}

int		sokoban(char **av)
{
  t_term	term_d;

  init_screen(&term_d);
  return (menu(av, &term_d));
}

int		main(int ac, char **av)
{
  if (ac == 2)
    {
      if (av[1][0] == 'k' && av[1][1] == 'e' && av[1][2] == 'y')
	return (key());
      else
	return (sokoban(av));
    }
  else
    return (84);
}
