/*
** my_popup.c for my_popup.c in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Mon Dec 19 23:13:44 2016 Tiphaine LAURENT
** Last update Fri Dec 23 00:17:34 2016 Tiphaine LAURENT
*/

#include "my.h"

int		my_popup(t_term *term_d, char *message)
{
  int		length;

  length = my_strlen(message);
  mvprintw(term_d->max_y / 2, term_d->max_x / 2 - length / 2, message);
  refresh();
  return (0);
}

void		create_maps(t_term *term_d)
{
  my_popup(term_d, "Creating a \"maps/\" directory...");
  mkdir("maps", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
  usleep(1000000);
  end_screen(84, term_d, "Fill it with all your maps : maps/map*");
}
