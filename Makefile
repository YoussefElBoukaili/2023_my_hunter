##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC      =		gcc

RM      =		rm -f

NAME    =		my_hunter

CSFML	=		-lcsfml-graphics -lcsfml-system

SRC		=		src/my_hunter.c		\
				src/my_hunter2.c	\
				src/init_game.c		\
				src/mini_printf.c	\

OBJ		=     	$(SRC:.c=.o)

all:        $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CSFML)

clean:
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) *.out
		$(RM) *.#
		$(RM) *.gnda
		$(RM) *.gndo

fclean:	clean
		$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
