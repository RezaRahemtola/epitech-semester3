##
## EPITECH PROJECT, 2023
## Day04am
## File description:
## Makefile
##

BASE_DIR	= 	.
BASE_FILES	=	z.c

SRC			=	$(addprefix $(BASE_DIR)/, $(BASE_FILES))

OBJ			=	$(SRC:.c=.o)

BINARY			=	z

HEADERS_DIRS 	=	include/

CFLAGS		=	-std=gnu17 -Wall -Wextra
CPPFLAGS	=	$(HEADERS_DIRS:%=-iquote %)

VG_FLAGS	=	--leak-check=full --track-origins=yes --show-leak-kinds=all \
				--error-limit=no --trace-children=no

CC			=	gcc
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
