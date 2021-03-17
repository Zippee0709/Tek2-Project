##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## C++ ex01
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-std=gnu11 -Wall -Wextra

CPPFLAGS += -Iinclude

SRC	=	main.c		\
		menger.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	menger

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
