##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./

MAIN	=	$(FOLDER)main.cpp				\

SRC	=	$(FOLDER)Object.cpp					\
		$(FOLDER)Box.cpp					\
		$(FOLDER)Conveyor.cpp				\
		$(FOLDER)GiftPaper.cpp				\
		$(FOLDER)IConveyorBelt.cpp			\
		$(FOLDER)IElf.cpp					\
		$(FOLDER)ITable.cpp					\
		$(FOLDER)LittlePony.cpp				\
		$(FOLDER)PapaXmasConveyorBelt.cpp	\
		$(FOLDER)PapaXmasElf.cpp			\
		$(FOLDER)PapaXmasTable.cpp			\
		$(FOLDER)Teddy.cpp					\
		$(FOLDER)Toy.cpp					\
		$(FOLDER)Wrap.cpp		\


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
