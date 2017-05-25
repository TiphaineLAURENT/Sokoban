/*
** menu.c for menu in /home/TiphaineLaurent/delivery/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Thu Dec 22 13:33:57 2016 Tiphaine LAURENT
** Last update Fri Dec 23 00:12:06 2016 Tiphaine LAURENT
*/

#include "my.h"

int			help(t_term *term_d)
{
  clear();
  my_popup(term_d, "Use ZQSD or Arrows to move your character 'P'");
  usleep(3000000);
  clear();
  my_popup(term_d, "Press Space to reset the map");
  usleep(3000000);
  clear();
  my_popup(term_d, "And \"Fin\" to end the game");
  usleep(3000000);
  clear();
  my_popup(term_d, "You got 30 seconds for a single map or you will loose");
  usleep(3000000);
  clear();
  return (0);
}
