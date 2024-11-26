#include "taskit.h"
#include <ctype.h>

static char	get_valid_priority()
{
	char	c;

	while (1)
	{
		c = get_char();
		switch (toupper(c))
		{
		case 'L':
		case 'M':
		case 'H':
			return c;

		default:
			printf(RED"%c is an invalid input\n"
					YEL"Please choose a valid input 'H' (High), "
					"'M' (Medium), 'L' (Low): "DFLT, c);
			break ;
		}
	}
}

Task	*task_new(int id)
{
	Task	*task;
	char	*desc = NULL;

	task = malloc(sizeof(*task));
	if (task == NULL)
		return NULL;

	printf("Enter task title (character limit: 50): ");
	get_s(task->title, sizeof(task->title));

	printf("Enter task description (Ctrl-D if done):\n");
	task->desc = NULL;
	while (get_line(&desc) != -1)
		task->desc = strjoin(task->desc, desc);

	printf("Enter task priority 'H': High, 'M': Medium, 'L': Low (one character): ");
	task->priority = get_valid_priority();

	task->id = id;
	return task;
}

void	add_task(Tasklist *tasklist)
{
	Task	*new_task;

	new_task = task_new(tasklist->size);
	if (new_task == NULL)
		; // Cleaning

	if (tasklist->head == NULL)
		tasklist->head = new_task;
	new_task->next = NULL;
	new_task->prev = tasklist->tail;
	tasklist->tail = new_task;
	tasklist->size++;
}
