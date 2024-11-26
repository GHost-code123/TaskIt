#include "taskit.h"
#include <ctype.h>

static char	get_valid_priority()
{
	char	c;

	while (1)
	{
		c = toupper(get_char());
		switch (c)
		{
		case 'L':
		case 'M':
		case 'H':
			return c;
		default:
			printf(RED"%c is an invalid input\n"
					YEL"Valid input 'H' (High), "
					"'M' (Medium), 'L' (Low)"DFLT, c);
			break ;
		}
	}
}

Task	*task_new()
{
	Task	*task;
	char	*desc = NULL;

	task = malloc(sizeof(*task));
	if (task == NULL)
		return NULL;

	printf("Enter task title (character limit: 50): ");
	get_s(task->title, sizeof(task->title));

	printf("Enter task description (Ctrl-D if done):\n");
	task->desc = "";
	while (get_line(&desc) != -1) {
		printf("here \n");
		task->desc = strjoin(task->desc, desc);
	}

	printf("Enter task priority (one character: 'H' (High), 'M' (Medium), 'L' (Low)): ");
	task->priority = get_valid_priority();
	printf("|%d|\n", task->priority);

	return task;
}

void	add_task(Tasklist *tasklist)
{
	Task	*new_task;

	new_task = task_new();
	if (new_task == NULL)
		; // Cleaning

	if (tasklist->head == NULL)
		tasklist->head = new_task;
	new_task->next = NULL;
	new_task->prev = tasklist->tail;
	tasklist->tail = new_task;
	tasklist->size++;
}
