##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

FOLDER  =	./src/

SRC	=	$(FOLDER)strlen.asm		\
		$(FOLDER)strchr.asm		\
		$(FOLDER)memset.asm		\
		$(FOLDER)memcpy.asm		\
		$(FOLDER)strcmp.asm		\
		$(FOLDER)strncmp.asm	\
		$(FOLDER)rindex.asm		\
		$(FOLDER)strstr.asm		\

OBJ	=	$(SRC:.asm=.o)

NAME	=	libasm.so

%.o: 	%.asm
		nasm -f elf64 -o $@ $<

all	:	$(NAME)

$(NAME) : $(OBJ)
		ld -shared -fPIC -nostdlib -o $@ $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
