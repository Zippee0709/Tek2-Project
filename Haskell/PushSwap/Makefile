##
## EPITECH PROJECT, 2019
## Makefile Haskell
## File description:
## Makefile
##

NAME	=	pushswap_checker

SRC	=	main.hs		\
##		pushswap.hs

OBJ =	$(SRC:.hs=.o)

all:	$(NAME)

$(NAME): $(SRC)
	ghc -Wall -o $(NAME) $(SRC)

clean:
	$(RM) *.hi
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
