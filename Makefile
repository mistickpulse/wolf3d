##
## Makefile for  in /home/fabian/rendu/lib_lapin/wolf3d
## 
## Made by Zouz
## Login   <fabian@epitech.net>
## 
## Started on  Tue May 24 01:24:44 2016 Zouz
##

NAME		= wolf3d

CC		= gcc

RM		= rm -rf

SRC		= main.c 				\
		  src/get_map.c 			\
		  src/my_getnbr.c			\
		  src/my_constgetnbr.c			\
		  src/ft_str.c				\
		  src/my_getfloat.c			\
		  src/mini_map.c			\
		  src/tek.c				\
		  src/keyboard.c			\
		  src/loop.c				\
		  src/wolf3d.c				\
		  src/putplayer.c			\
		  src/tekline.c				\
		  src/environment.c			\
		  src/raycasting.c			\
		  src/mouvement.c			\
		  src/get_map_2.c

OBJ		= $(SRC:.c=.o)

LAPIN           = -L${HOME}/.froot/lib/ -llapin 	\
		  -lsfml-audio 				\
		  -lsfml-graphics 			\
		  -lsfml-window 			\
		  -lsfml-system 			\
		  -lstdc++ -ldl

MATH		= -lm

CFLAGS		= -W -Wall -Iinclude -I${HOME}/.froot/inlude/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LAPIN) $(MATH)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
