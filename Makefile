##
## EPITECH PROJECT, 2025
## rubiks_cube_solver
## File description:
## Makefile
##

COMP = g++
FLAGS = -Wall -Wextra -Werror -std=c++17 -fPIC -fno-gnu-unique -g3
RM = rm -rf
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lX11 -lXrandr -lXcursor -lXrender -lGL -lGLU -ludev -lXi -fPIC

NAME = rcs

SRC = src/main.cpp		\
		src/Pattern.cpp	\
		src/Display.cpp	\
		src/Solve.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) -o $@ $^ $(SFML_FLAGS) -I includes

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
