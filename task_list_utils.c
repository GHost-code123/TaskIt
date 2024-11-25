#include "taskit.h"

void	add_task(Task *task_list)
{
	Task	*new_task;

	new_task = malloc(sizeof(*new_task));
	if (new_task == NULL) {
		// Cleaning
		return ;
	}
	printf("Enter task title (character limit: 50): ");
	get_s(new_task->title, sizeof(new_task->title));
	printf("Enter task description:\n");
	while (getline())
}

