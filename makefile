NAME = taskit

INC = taskit.h color.h

SRC = main.c taskit.c utils.c

all:
	@gcc -fsanitize=address $(SRC) -o $(NAME)