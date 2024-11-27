NAME = taskit

INC = taskit.h color.h

SRC = main.c taskit.c task_list_utils.c str_utils.c utils.c ui.c

all:
	@gcc -fsanitize=address $(SRC) -o $(NAME)
