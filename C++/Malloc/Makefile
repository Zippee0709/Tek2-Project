##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	src/

SRC	=	$(FOLDER)malloc.c				\
		$(FOLDER)free.c					\

OBJ	=	$(MAIN:.cpp=.o)				\
		$(SRC:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS +=	-Iinclude

NAME	=	libmy_malloc.so

all	:
		gcc -fPIC -shared $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(SRC)

clean	:
		rm -f *.o

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
