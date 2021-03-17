##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./

MAIN	=	$(FOLDER)main.cpp				\

SRC	=	$(FOLDER)Component/Component.cpp		\
		$(FOLDER)Component/OrGate.cpp			\
		$(FOLDER)Component/AndGate.cpp			\
		$(FOLDER)Component/Input.cpp			\
		$(FOLDER)Component/Output.cpp			\
		$(FOLDER)Component/Pin.cpp			\
		$(FOLDER)Component/True.cpp			\
		$(FOLDER)Component/False.cpp			\
		$(FOLDER)Component/Clock.cpp			\
		$(FOLDER)Component/Factory.cpp			\
		$(FOLDER)Component/NorGate.cpp			\
		$(FOLDER)Component/NandGate.cpp			\
		$(FOLDER)Component/Gate4030.cpp			\
		$(FOLDER)Component/Gate4069.cpp			\
		$(FOLDER)Component/FourBitAdder.cpp		\
		$(FOLDER)Exception/InvalidArgv.cpp		\
		$(FOLDER)Exception/PinException.cpp		\
		$(FOLDER)Parsing/Parsing.cpp			\
		$(FOLDER)Parsing/Argv.cpp			\
		$(FOLDER)GetCommand/getCommand.cpp		\

OBJ	=	$(MAIN:.cpp=.o)				\
		$(SRC:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -g

CXXFLAGS +=	-I./

NAME	=	nanotekspice

all	:	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
