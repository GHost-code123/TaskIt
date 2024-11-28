NAME = taskit

INC = taskit.h color.h

SRC =	main.c taskit.c taskit_utils.c  task_list_utils.c \
		user_utils.c str_utils.c utils.c ui_ux.c

all:
	@gcc $(SRC) -o $(NAME)  # -fsanitize=address
