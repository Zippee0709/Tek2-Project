##
## EPITECH PROJECT, 2020
## cpp_d02m_2019
## File description:
## Makefile
##

CC	?=	gcc

RM	?=	rm -rf

SRC	=	../ex01/new.c \
		../ex01/player.c \
		../ex03/point.c \
		../ex03/vertex.c 	\

SRC_TEST	=	tester_point_02.c \
				tester_vertex_02.c  \
				tester_adder_03.c \
				test_sub_03.c \


CFLAGS	=	-std=gnu11 -Wall -Wextra -W

NAME	=	unit_tests

OBJ = $(SRC:.c=.o)

tests_run: fclean $(OBJ)
	$(CC) $(OBJ) $(SRC_TEST) -o $(NAME) -lcriterion --coverage
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

mr_clean :
	find -type f -name "*~" -delete -o -type f -name "#*#" -delete

.PHONY : all clean fclean mr_clean tests_run re