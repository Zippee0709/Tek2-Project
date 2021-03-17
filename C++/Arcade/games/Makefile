##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	lib_arcade_pacman.so

SRC		=	Pacman.cpp		\
			Game.cpp		\
			Character.cpp	\

OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -c -fpic $(SRC)
	g++ -shared -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
