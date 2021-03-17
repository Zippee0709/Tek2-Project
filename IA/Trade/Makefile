##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make files
##

NAME	=	trade

SRC		=	src/trade.py

all:
	cp $(SRC) $(NAME)
	chmod 755 $(NAME)

# tests_run:
# 		python3 test_groundhog.py

clean:
	echo "Nothing to clean"

fclean:	clean
	rm $(NAME)	\
	rm -f *~	\
	rm -f *#	\

re:	fclean clean all

.PHONY:	all re clean fclean
