##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	string.c	\
		assign.c	\
		utilities.c	\
		copy.c		\
		my_func.c

OBJ = $(SRC:.c=.o)

NAME = libstring.a

all :	$(OBJ)
		ar rc $(NAME) $(OBJ)
		gcc -g3 -Wall -Wextra main_tony.c -L. -lstring

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)
		rm -f a.out
		rm -f vgcore*

re	:	fclean all

.PHONY: all clean fclean re
