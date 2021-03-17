##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./

MAIN	=	$(FOLDER)main.cpp		\

SRC	=	$(FOLDER)WarpSystem.cpp		\
		$(FOLDER)Federation.cpp		\
		$(FOLDER)Borg.cpp			\

OBJ	=	$(MAIN:.cpp=.o)				\
		$(SRC:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

CPPFLAGS +=	-Iinclude

NAME	=	a.out

all	:	$(OBJ)
		g++ $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(SRC) $(MAIN)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
