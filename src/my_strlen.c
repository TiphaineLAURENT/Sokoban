/*
** my_strlen.c for my_strlen in /home/TiphaineLaurent/PSU_2016_my_sokoban/sokobanV2/sokobanV3
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Mon Dec 19 23:12:32 2016 Tiphaine LAURENT
** Last update Mon Dec 19 23:13:26 2016 Tiphaine LAURENT
*/

int		my_strlen(char *str)
{
  int		length;

  length = 0;
  while (str[length])
    length += 1;
  return (length);
}
