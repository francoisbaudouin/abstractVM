##
## EPITECH PROJECT, 2022
## abstractVM
## File description:
## Makefile
##


NAME = abstractVM

TEST_N	=	unit_tests

SRC =	src/main.cpp\
		src/parser/Parser.cpp \

SRC_T	=

OBJ	=	$(SRC:.cpp=.o)

CXX = g++

CXXFLAGS += -std=c++20 -Wextra -Wall -Wreorder -Wshadow -Isrc/ -g

TFLAGS	=	-lcriterion --coverage -Isrc/

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ)

re: fclean all

clean:
	$(RM) $(OBJ)

fclean:	clean clean_test
	$(RM) $(NAME)

clean_test:
	rm -f unit_tests
	rm -f *.gcno
	rm -f *.gcda

tests_run: fclean
	$(CC) -o $(TEST_N) $(SRC_T) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/

.PHONY : all main clean fclean