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
	char	priority; // Possible values: 'H' (High), 'M' (Medium), 'L' (Low)
	char	duedate[13];
	Status	stat;
	struct s_task	*prev;
	struct s_task	*next;
}	Task;

typedef struct {
	int	compl_tasks;
	int	incompl_tasks;
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
void	edit_task(Tasklist *task_list);
void	delete_task(Tasklist *task_list);
void	show_task(Tasklist *task_list);

// Task list functions:
Task	*tasklist_new();
void	tasklist_add(Tasklist *tasklist, Task *newtask);
void	tasklist_del(Tasklist *tasklist, Task *task);
Task	*get_task_byId(Tasklist *tasklist, int id);


// Utils:
void	exit_app(Tasklist *tasklist);
void	fatal_error(Tasklist *tasklist);
void	free_task(Task *task);
void	free_tasklist(Tasklist *tasklist);

// Other Utils:
int	isvalid_date(struct tm *date);

char	*strjoin(char *s1, char *s2);
char	*get_s(char *s, size_t n);
int		get_line(char **s);
char		get_char();
void	clear_stdin();

// UI:
void	show_tasks_table(Tasklist *tasklist, int show_options, int show_more);
void	show_banner(const char *username);
void	show_main_menu();
void	show_tskmng_menu();
void	ask_to_continue();

#endif
