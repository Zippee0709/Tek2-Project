##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./core

MAIN	=	main.cpp				\

SRC	=	$(FOLDER)/Core.cpp			\
		$(FOLDER)/Error.cpp			\

OBJ	=	$(MAIN:.cpp=.o)				\
		$(SRC:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -g3 -ldl -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lncurses -lstdc++fs

CXXFLAGS +=	-I./

NAME	=	arcade

all	:	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)
		make -C ./lib
		make -C ./games

graphicals:
		make -C ./lib

games:
		make -C ./games

core:	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)
		make clean -C ./lib
		make clean -C ./games

fclean:	clean
		rm -f $(NAME)
		make fclean -C ./lib
		make fclean -C ./games

re	:	fclean all
		make re -C ./lib
		make re -C ./games

.PHONY	:	all clean fclean re
