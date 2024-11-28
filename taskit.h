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

typedef enum {
	LOW,
	MED,
	HIGH
}  Prior;

extern const char	*priorities[];

typedef struct s_task {
	int		id;
	char	title[51];
	char	*desc;
	Prior	priority; // Possible values: 'H' (High), 'M' (Medium), 'L' (Low)
	Status	stat;
	char	duedate[11];

	char	*creattime;
	char	*modiftime;

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
void	show_filt_task(Tasklist *task_list);
void	show_filt_tasks_table(Tasklist *tasklist);
void	show_task_details(Task *task, FILE *stream);
void	show_task(Tasklist *task_list, int stat_filt, int prior_filt);
void	sort_task_list(Tasklist *tasklist);

// Task list functions:
Task	*tasklist_new();
void	tasklist_add(Tasklist *tasklist, Task *newtask);
void	tasklist_del(Tasklist *tasklist, Task *task);
Task	*get_task_byId(Tasklist *tasklist, int id);
void	tasklist_sort_byId(Tasklist *tasklist);
void	tasklist_sort_byDate(Tasklist *tasklist);
void	tasklist_sort_byPriority(Tasklist *tasklist);


// Utils:
void	exit_app(Tasklist *tasklist);
void	fatal_error(Tasklist *tasklist);
void	free_task(Task *task);
void	free_tasklist(Tasklist *tasklist);

// User utils:
void	save_user_tasklist(Tasklist *tasklist, const char *username);

// Other Utils:
int		isvalid_date(struct tm *date);
char	*get_curtime();

char	*strjoin(char *s1, char *s2);
char	*get_s(char *s, size_t n);
int		get_line(char **s);
char	get_char();
void	clear_stdin();

// UI/UX:
void	show_tasks_table(Tasklist *tasklist, int stat_filt, int prior_filt);
void	show_banner(const char *username);
void	show_main_menu();
void	show_tskmng_menu();
void	ask_to_continue();
int		confirm_prompt();

#endif
