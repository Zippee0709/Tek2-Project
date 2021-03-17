##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./

MAIN	=	$(FOLDER)main.cpp				\

SRC	=	$(FOLDER)Lemon.cpp	\
		$(FOLDER)Banana.cpp		\
		$(FOLDER)Fruit.cpp		\
		$(FOLDER)FruitBox.cpp		\
		$(FOLDER)Lime.cpp		\
		$(FOLDER)LittleHand.cpp		\

OBJ	=	$(MAIN:.cpp=.o)				\
		$(SRC:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

CPPFLAGS +=	-Iinclude

NAME	=	a.out

all	:
		g++ -Wall -Wextra -o $(NAME) $(MAIN) $(SRC)

clean	:
		rm -f *.o

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
