##
## EPITECH PROJECT, 2020
## imageCompressor
## File description:
## Makefile
##

NAME = imageCompressor

SRC =  app/Main.hs \

OBJ = $(SRC:.hs=.o)

OBJS = $(SRC:.hs=.hi)

SETUP = Setup.o \
		Setup.hi \

all : $(NAME)

$(NAME) : $(SRC)
	stack build
	cp ./.stack-work/dist/x86_64-linux-tinfo6/Cabal-2.4.0.1/build/imageCompressor/imageCompressor ./

clean :
	stack clean

fclean : clean
	$(RM) $(NAME)
	stack purge

re: fclean all

.PHONY : all clean fclean re
