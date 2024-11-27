#ifndef TASKIT_H
# define TASKIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <ctype.h>

# include "color.h"

/* 
 * Data structures:
 */

typedef enum {
	INCOMPLETED,
	COMPLETED
}  Status;

typedef struct s_task {
	int		id;
	char	title[51];
	char	*desc;
	char	priority; // Possoble values: 'H' (High), 'M' (Medium), 'L' (Low)
	char	duedate[13];
	Status	stat;
	struct s_task	*prev;
	struct s_task	*next;
}	Task;

typedef struct {
	size_t	size;
	Task	*head;
	Task	*tail;
} Tasklist;


/* 
 * Functions:
 */

// Task management:
void	manage_tasks(Tasklist *task_list);
void	add_task(Tasklist *task_list);
Task	*task_new(int id);

// Utils:
int	isvalid_date(struct tm *date);

char	*strjoin(char *s1, char *s2);
char	*get_s(char *s, size_t n);
int		get_line(char **s);
int		get_char();
void	clear_stdin();

// UI:
void	show_tasks_table(Tasklist *tasklist, int show_options, int show_more);
void	show_banner(const char *username);
void	show_main_menu();
void	show_tskmng_menu();
void	ask_to_continue();

#endif
