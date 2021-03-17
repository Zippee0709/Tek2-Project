##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

##TESTFOLDER =	./tests/

##TESTSRC	=	$(TESTFOLDER)test_my_strlen.c	\

##CRITERION =	--coverage -lcriterion

##CRINAME =	unit_tests

FOLDER  =	./

MAIN	=	$(FOLDER)main.cpp			\

SRC	=	$(FOLDER)my_cat.cpp			\

OBJ	=	$(MAIN:.cpp=.o)				\

CFLAGS	+=	-W -Wall -Wextra -Werror -g3

CPPFLAGS +=	-Iinclude

NAME	=	my_cat

all	:	$(OBJ)
		g++ $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ)
## 		gcc $(CPPFLAGS) -o $(CRINAME) $(TESTSRC) $(SRC) $(LIB) $(CRITERION)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
#		rm -f $(CRINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
