##
## Makefile for Makefile in /home/TiphaineLaurent/PSU_2016_my_popup
## 
## Made by Tiphaine LAURENT
## Login   <TiphaineLaurent@epitech.net>
## 
## Started on  Mon Dec 12 12:19:25 2016 Tiphaine LAURENT
## Last update Thu May 25 16:22:45 2017 Tiphaine LAURENT
##

CC		=	gcc -o
CFLAGS		=	-Wall -Wextra -Werror
##CFLAGS	+=	-g3
CPPFLAGS	+=	-I ./include

LDFLAGS		=	-lncurses

NAME		=	my_sokoban

SRC_DIR		=	src/
SRC_FILES	=	sokobanV3.c	\
			my_strlen.c	\
			my_popup.c	\
			screen.c	\
			get_map.c	\
			disp_map.c	\
			movement.c	\
			fct_move.c	\
			box_move.c	\
			time.c		\
			menu.c		\
			help.c		\
			check_map.c	\
			path.c		\
			score.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

RM		=	rm -f

OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
