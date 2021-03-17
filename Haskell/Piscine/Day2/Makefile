##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for Haskell project
##

CRITERION =	--coverage -lcriterion

CRINAME =	unit_tests

SRC	=	DoOp.hs

OBJ =	$(SRC:.hs=.hi) $(MAIN:.hs=.hi)

CFLAGS	+=	-W -Wall -Wextra

NAME	=	doop

all	:
		ghci $(SRC)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re