##
## EPITECH PROJECT, 2023
## libmy
## File description:
## Makefile
##

SRC		=	my_string.c \
			my_string_utils.c \
			my_string_actions.c \
			my_string_manipulate.c \
			my_string_advanced.c \
			my_string_end.c

OBJ		=	$(SRC:.c=.o)

NAME	=	libstring.a

INC		=	.

AR		=	ar rc
CC		=	gcc
CFLAGS	=	-std=gnu17 -Wall -Wextra
CPPFLAGS =	-iquote $(INC)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
