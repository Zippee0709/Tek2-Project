##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make files
##

NAME	=	pac

SRC	=	Pacman.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)	\
	rm -f *~	\
	rm -f *#	\

re:	fclean clean all

.PHONY:	all re clean fclean