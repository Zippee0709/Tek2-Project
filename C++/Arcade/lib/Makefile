##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAMESFML	=	lib_arcade_sfml.so

SRCSFML		=	my_sfml.cpp	\
			Cursor.cpp	\

OBJSFML		=	$(SRCSFML:.cpp=.o)

NAMENCURSES	=	lib_arcade_ncurses.so

SRCNCURSES	=	my_ncurses.cpp	\

OBJNCURSES	=	$(SRCNCURSES:.cpp=.o)

SRCCOMMON	=	Graphic.cpp	\
				GraphicCharacter.cpp

OBJCOMMON	=	$(SRCCOMMON:.cpp=.o)

all:	ncurses sfml

ncurses:	$(OBJNCURSES) $(OBJCOMMON)
	g++ -c -fPIC $(SRCNCURSES) $(SRCCOMMON) 
	g++ -shared -o $(NAMENCURSES) $(OBJNCURSES) $(OBJCOMMON)

sfml:	$(OBJSFML) $(OBJCOMMON)
	g++ -c -fPIC $(SRCSFML) $(SRCCOMMON)
	g++ -shared -o $(NAMESFML) $(OBJSFML) $(OBJCOMMON)

clean:
	rm -f $(OBJNCURSES)
	rm -f $(OBJSFML)
	rm -f $(OBJCOMMON)

fclean:	clean
	rm -f $(NAMENCURSES)
	rm -f $(NAMESFML)

re:	fclean all
