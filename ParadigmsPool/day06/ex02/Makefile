##
## EPITECH PROJECT, 2023
## Day06
## File description:
## Makefile
##

BASE_DIR	= 	.
BASE_FILES	=	RetardUnitConverter.cpp

SRC			=	$(addprefix $(BASE_DIR)/, $(BASE_FILES))

OBJ			=	$(SRC:.cpp=.o)

BINARY			=	RetardUnitConverter

HEADERS_DIRS 	=	include/

CFLAGS		=	-std=c++20 -Wall -Wextra -Werror
CPPFLAGS	=	$(HEADERS_DIRS:%=-iquote %)

VG_FLAGS	=	--leak-check=full --track-origins=yes --show-leak-kinds=all \
				--error-limit=no --trace-children=no

CC			=	g++
VG			=	valgrind $(VG_FLAGS)

all:	$(BINARY)

$(BINARY):	$(OBJ)
			$(CC) -o $(BINARY) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(BINARY)

re:	fclean all

.PHONY:	all	clean fclean re
