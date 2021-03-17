##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./

MAIN	=	$(FOLDER)main.cpp			\

SRC	=	$(FOLDER)my_cat.cpp			\

OBJ	=	$(MAIN:.cpp=.o)				\

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

CPPFLAGS +=	-Iinclude

NAME	=	my_convert_temp

all	:	$(OBJ)
		g++ $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
