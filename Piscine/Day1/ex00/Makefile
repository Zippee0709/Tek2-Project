##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## C++ ex00
##

CC	=	gcc

RM	=	rm -rf

CPPFLAGS	=	-std=gnu11 -Wall -Wextra

SRC	=	z.c

OBJ	=	$(SRC:.c=.o)

NAME	=	z

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
