/*
** menu.c for menu in /home/TiphaineLaurent/delivery/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Thu Dec 22 13:33:57 2016 Tiphaine LAURENT
** Last update Fri Dec 23 01:12:10 2016 Tiphaine LAURENT
*/

#include "my.h"

int			all_map(t_term *term_d)
{
  DIR			*dir;
  struct	dirent	*file;
  struct	stat	file_d;
  int			end;

  stat("./maps", &file_d);
  if (!S_ISDIR(file_d.st_mode))
    create_maps(term_d);
  dir = opendir("./maps");
  end = 1;
  while ((file = readdir(dir)) && end != 0)
    {
      mvprintw(15, 15, "Your score : %d", end);
      if (file->d_name[0] != '.' && file->d_name[0] == 'm' && file->d_name[1] == 'a'
	  && file->d_name[2] == 'p')
	end *= game(create_path(file->d_name, term_d), term_d);
    }
  closedir(dir);
  score(end, term_d);
  if (end == 0)
    return (end_screen(1, term_d, "YOU LOST !"));
  else
    return (end_screen(0, term_d, "YOU WON !"));
}

int			cur_down(int y)
{
  mvprintw(y, 1, " ");
  if (y + 2 > 7)
    y = 1;
  else
    y += 2;
  return (y);
}

int			cur_up(int y)
{
  mvprintw(y, 1, " ");
  if (y - 2 < 1)
    y = 7;
  else
    y -= 2;
  return (y);
}

int			disp_choice(int y)
{
  mvprintw(1, 2, "PLAY CHOOSEN MAP");
  mvprintw(3, 2, "PLAY ALL THE MAP");
  mvprintw(5, 2, "HELP");
  mvprintw(7, 2, "EXIT");
  mvprintw(y, 1, "-");
  return (0);
}

int			menu(char **av, t_term *term_d)
{
  int			key;
  int			y;

  y = 1;
  while ((key = getch()) != 3)
    {
      disp_choice(y);
      if (key == 258)
	y = cur_down(y);
      if (key == 259)
	y = cur_up(y);
      if (key == 10)
	{
	  if (y == 1)
	    game(av[1], term_d);
	  if (y == 3)
	    all_map(term_d);
	  if (y == 5)
	    help(term_d);
	  if (y == 7)
	    return (end_screen(2, term_d, "Exiting SOKOBAN"));
	  clear();
	}
    }
  return (0);
}
