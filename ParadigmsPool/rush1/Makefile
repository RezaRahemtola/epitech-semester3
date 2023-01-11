##
## EPITECH PROJECT, 2023
## Haskell rush1
## File description:
## Makefile
##

SRC			=	src/Entry.hs			\
				src/Parsing.hs			\
				src/PushSwapChecker.hs	\
				app/Main.hs

TST			=	test/Spec.hs

NAME		=	pushswap_checker

CFLAGS		=	-Wall -Wextra

all: $(NAME)

$(NAME): $(SRC)
	ghc $(CFLAGS) $(SRC) -o $(NAME)

stack_build:
	stack build --copy-bins --local-bin-path .

clean:
	$(RM) $(SRC:.hs=.hi)
	$(RM) $(SRC:.hs=.o)

fclean: clean
	$(RM) $(NAME)

tests_run:
	stack test --coverage
	stack hpc report --all --destdir test/coverage/

re:		fclean all

.PHONY: all clean fclean re stack_build tests_run
