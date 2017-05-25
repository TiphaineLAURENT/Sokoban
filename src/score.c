/*
** score.c for score in /home/TiphaineLaurent/delivery/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Thu Dec 22 22:06:57 2016 Tiphaine LAURENT
** Last update Tue Dec 27 14:56:46 2016 Tiphaine LAURENT
*/

#include "my.h"

int			is_same(char *str1, char *str2)
{
  while (*str1 && *str2)
    {
      if (*str1 != *str2)
	return (0);
      str1 += 1;
      str2 += 1;
    }
  return (1);
}

int			my_getnbr(char *nbr)
{
  int			result;

  result = 0;
  while (*nbr >= '0' && *nbr <= '9')
    {
      result *= 10;
      result += *nbr - '0';
      nbr += 1;
    }
  return (result);
}

int			read_maxscore(t_term *term_d)
{
}

int			score(int score, t_term *term_d)
{
  int			file;
  struct	stat	file_d;
  char			*buffer;
  char			*name;

  if (!(file = open("scores", O_CREAT | O_RDWR, S_IRWXU | S_IRGRP | S_IROTH)))
    return (end_screen(84, term_d, "Error while opening/creating scores"));
  fstat(file, &file_d);
  buffer = malloc(sizeof(char) * file_d.st_size);
  if (read(file, buffer, file_d.st_size) == -1 || buffer == NULL)
    return (end_screen(84, term_d, "Error while reading scores"));
  my_popup(term_d, "Enter your name (only minor characters [a-z]");
  scanf("%m[a-z]", &name);
  dprintf(file, "\nscore_%s=%d", name, score);
  close(file);
  free(buffer);
  return (0);
}
