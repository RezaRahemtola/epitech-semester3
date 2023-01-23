##
## EPITECH PROJECT, 2023
## Day06
## File description:
## Makefile
##

BASE_DIR	= 	.
BASE_FILES	=	Peasant.cpp

SRC			=	tmp/ex00_main.cpp \
				$(addprefix $(BASE_DIR)/, $(BASE_FILES))

OBJ			=	$(SRC:.cpp=.o)

BINARY			=	RetardUnitConverter

HEADERS_DIRS 	=	.

CXXFLAGS		=	-Wall -Wextra -Werror -std=c++20
CPPFLAGS		=	$(HEADERS_DIRS:%=-iquote %)

VG_FLAGS	=	--leak-check=full --track-origins=yes --show-leak-kinds=all \
				--error-limit=no --trace-children=no

CXX			=	g++
VG			=	valgrind $(VG_FLAGS)

all:	$(BINARY)

$(BINARY):	$(OBJ)
			$(CXX) -o $(BINARY) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(BINARY)

re:	fclean all

.PHONY:	all	clean fclean re
