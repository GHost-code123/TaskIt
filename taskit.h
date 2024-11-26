#ifndef TASKIT_H
# define TASKIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "color.h"

# include "color.h"


typedef struct s_task {
	int		id;
	char	title[51];
	char	*desc;
	char	priority; // Possoble values: 'H' (High), 'M' (Medium), 'L' (Low)
	char	duedate[11];
	struct s_task	*prev;
	struct s_task	*next;
}	Task;

typedef struct {
	size_t	size;
	Task	*head;
	Task	*tail;
} Tasklist;


void	manage_tasks();
void	add_task(Tasklist *task_list);
Task	*task_new(int id);

// Utils:
char	*strjoin(char *s1, char *s2);
char	*get_s(char *s, size_t n);
int		get_line(char **s);
int		get_char();
void	clear_stdin();

// UI:
void	show_banner(const char *username);
void	show_main_menu();

#endif /* TASKIT_H */
