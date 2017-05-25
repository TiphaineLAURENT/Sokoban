/*
** my.h for my in /home/TiphaineLaurent/PSU_2016_my_popup
** 
** Made by Tiphaine LAURENT
** Login   <TiphaineLaurent@epitech.net>
** 
** Started on  Mon Dec 12 12:27:29 2016 Tiphaine LAURENT
** Last update Tue Dec 27 14:51:39 2016 Tiphaine LAURENT
*/

#ifndef MY_H_
# define MY_H_

# define DELAY 30000

# include <ncurses.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <time.h>

typedef	struct	s_term
{
  int		max_x;
  int		max_y;
  time_t	start_time;
}		t_term;

typedef	struct	s_map
{
  char		obj;
  char		obj2;
}		t_map;

typedef struct	s_move
{
  int		key;
  t_map		**(*moves)(t_map **, t_term *);
}		t_move;

typedef struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef	struct	s_check
{
  int		p;
  int		x;
  int		o;
}		t_check;

typedef	struct	s_time
{
  time_t	game_time;
  int		delta;
}		t_time;

typedef	struct	s_end
{
  int		is_end;
  int		score;
}		t_end;

int		sokoban(char **);
int		my_strlen(char *);
int		my_popup(t_term *, char *);
int		init_screen(t_term *);
int		end_screen(int, t_term *, char *);
t_map		**get_map(char *, t_term *);
int		disp_map(t_map **, t_term *);
t_map		**get_and_disp(char *, t_term *, int);
t_pos		*get_pos(t_map **, t_pos *);
int		is_free(t_map **, int, int);
t_map		**move_left(t_map **, t_term *);
t_map		**move_right(t_map **, t_term *);
t_map		**move_up(t_map **, t_term *);
t_map		**move_down(t_map **, t_term *);
t_map		**box_left(t_map **, int, int);
t_map		**box_right(t_map **, int, int);
t_map		**box_up(t_map **, int, int);
t_map		**box_down(t_map **, int, int);
int		game(char *, t_term *);
int		timer(t_time *, t_term *);
int		timer_pause(t_time *, t_term *);
int		score(int, t_term *);
int		check_map(t_map **, t_term *);
int		menu(char **, t_term *);
int		help(t_term *);
void		create_maps(t_term *);
char		*create_path(char *, t_term *);

#endif
