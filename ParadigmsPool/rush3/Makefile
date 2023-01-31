##
## EPITECH PROJECT, 2023
## Rush 3
## File description:
## Makefile of the project
##

HEADERS_DIR		=	include
SRC_DIR			=	src
TEXT_SRC		= 	Display.cpp
GRAPHICAL_SRC	=	Display.cpp
MODULES_SRC		=	OperatingSystem.cpp \
					HostNames.cpp \
					DateTime.cpp \
					Memory.cpp
BASE_SRC		=	$(addprefix modules/, $(MODULES_SRC)) \
					$(addprefix text/, $(TEXT_SRC)) \
					$(addprefix graphical/, $(GRAPHICAL_SRC)) \
          			Option.cpp \
					Utils.cpp
SRC				=	$(addprefix $(SRC_DIR)/, $(BASE_SRC))
OBJ				=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)
MAIN			=	$(SRC_DIR)/Main.cpp
TST_DIR			=	tests
TST				=
TST_OBJ			=	$(SRC:.cpp=.o) $(TST:.cpp=.o)
LIB_DIR			=	lib
LIBS 			=   ncurses sfml-graphics sfml-window sfml-system

BINARY			=	MyGKrellm
TST_BINARY		= 	$(BINARY).test
DEBUG_BINARY	=	$(BINARY).debug

CPPFLAGS 		+= 	-Wall -Wextra -iquote $(HEADERS_DIR) -std=c++20
CXXFLAGS		+=
LDFLAGS 		+= 	-L $(LIB_DIR)
LDLIBS			+= 	$(addprefix -l, $(LIBS))

CXX				= g++

# Build targets:

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CXX) $(OBJ) -o $(BINARY) $(LDFLAGS) $(LDLIBS)

$(TST_BINARY): LIBS		+=	criterion gcov
$(TST_BINARY): CPPFLAGS 	+=	-ftest-coverage -fprofile-arcs
$(TST_BINARY): $(TST_OBJ)
	$(CXX) $(TST_OBJ) -o $(TST_BINARY) $(LDFLAGS) $(LDLIBS)

$(DEBUG_BINARY): CXXFLAGS +=	-g
$(DEBUG_BINARY): $(OBJ)
	$(CXX) $(OBJ) -o $(DEBUG_BINARY) $(LDFLAGS) $(LDLIBS)

re:	fclean all

# Other targets:

tests_run: $(TST_BINARY)
	./$(TST_BINARY)
	gcovr --exclude $(TST_DIR)
	gcovr --exclude $(TST_DIR) --branches

debug: re $(DEBUG_BINARY)

# Cleaning targets:

clean:
	$(RM) $(OBJ) $(TST_OBJ)

fclean: clean
	$(RM) $(BINARY) $(TST_BINARY) $(DEBUG_BINARY)

aclean: fclean
	find . \( -name "#*#" -o -name "*~" -o -name "*.gcda" \
	-o -name "*.gcno" -o -name "vgcore.*" \) -delete

# Makefile's safety:

.PHONY: all clean fclean aclean tests_run re debug
