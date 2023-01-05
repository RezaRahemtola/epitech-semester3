##
## EPITECH PROJECT, 2023
## Haskell
## File description:
## Makefile
##

SRC   =    DoOp.hs

NAME  =    doop

RM    =    rm -f

HFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):
	@ghc $(HFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(SRC:.hs=.hi)
	$(RM) $(SRC:.hs=.o)

fclean:        clean
	$(RM) $(NAME)

re:        fclean all

.PHONY: all clean fclean re
