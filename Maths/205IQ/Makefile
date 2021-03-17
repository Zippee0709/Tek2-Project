##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make files
##

NAME	=	205IQ

SRC		=	IQ205.py

all:
	cp $(SRC) $(NAME)
	chmod 755 $(NAME)

tests_run:
		python3 test_IQ205.py

clean:
	echo "Nothing to clean"

fclean:	clean
	rm $(NAME)	\
	rm -f *~	\
	rm -f *#	\
	rm -rf __pycache__

re:	fclean clean all

.PHONY:	all re clean fclean
