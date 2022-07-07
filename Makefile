##
## EPITECH PROJECT, 2022
## math
## File description:
## Makefile
##


SRC =	stack.cpp

CXX =		g++

CXXFLAGS =	-W -Wall -Wextra -I./

LDFLAGS =

NAME =		stack

OBJ =		$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
