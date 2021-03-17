##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./

MAIN	=	$(FOLDER)main.cpp		\

SRC	=	$(FOLDER)Plazza/Plazza.cpp		\
		$(FOLDER)Reception/Reception.cpp		\
		$(FOLDER)Exception/PlazzaException.cpp	\
		$(FOLDER)Exception/MutexException.cpp	\
		$(FOLDER)Exception/ThreadException.cpp	\
		$(FOLDER)Kitchen/Kitchen.cpp		\
		$(FOLDER)Kitchen/Mutex.cpp		\
		$(FOLDER)Kitchen/ScopedLock.cpp		\
		$(FOLDER)Kitchen/Thread.cpp		\
		$(FOLDER)Plazza/SharedMemory.cpp	\

OBJ	=	$(MAIN:.cpp=.o)				\
		$(SRC:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -g3 -pthread

CXXFLAGS +=	-I./

NAME	=	plazza

all	:	$(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
