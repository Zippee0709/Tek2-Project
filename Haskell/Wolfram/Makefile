##
## EPITECH PROJECT, 2019
## Makefile Haskell
## File description:
## Makefile
##

NAME	=	wolfram

SRC	=	main.hs		\
##		pushswap.hs

OBJ =	$(SRC:.hs=.o)

all:	$(NAME)

$(NAME): $(SRC)
	ghc -fwarn-incomplete-patterns -Wall -Wextra -o $(NAME) $(SRC)

clean:
	$(RM) *.hi
	$(RM) *.o

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
