##
## EPITECH PROJECT, 2022
## PDG-Rush2
## File description:
## Makefile
##

SRC			=	char.c \
				int.c \
				float.c \
				new.c \
				point.c \
				vertex.c

INC			=	tests/include/

TEST		=	unit_tests
TESTS		=	tests/test_rush.c

CC			=	gcc
RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Wpedantic -std=gnu17
CPPFLAGS	=	-iquote $(INC)
TESTFLAGS	=	--coverage -lcriterion $(CPPFLAGS) $(CFLAGS)

clean:
	$(RM) *.gcda
	$(RM) *.gcno

fclean:	clean
	$(RM) $(TEST)

re:	fclean

tests_run: $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	$(CC) -o $(TEST) $(SRC) $(TESTS) $(TESTFLAGS)
	./$(TEST)

.PHONY: all clean fclean re tests_run
