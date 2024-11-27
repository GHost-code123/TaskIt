#include "taskit.h"

Task	*tasklist_new()
{
	Task	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return NULL;

	new->prev = NULL;
	new->next = NULL;
	return new;
}

void	tasklist_add(Tasklist *tasklist, Task *newtask)
{
	if (tasklist->head == NULL)
		tasklist->head = newtask;
	newtask->next = NULL;
	newtask->prev = tasklist->tail;
	tasklist->tail = newtask;
	tasklist->size++;
}

void	tasklist_del(Tasklist *tasklist, Task *task)
{
	if (tasklist->head == task)
		tasklist->head == task->next;
	if (tasklist->tail == task)
		tasklist->tail == task->prev;
	tasklist->size--;
	if (task->stat == COMPLETED)
		tasklist->compl_tasks--;
	else
		tasklist->incompl_tasks++;

	if (task->prev)
		task->prev->next = task->next;
	if (task->next)
		task->next->prev = task->prev;
	
	free_task(task);
}

Task	*get_task_byId(Tasklist *tasklist, int id)
{
	Task	*task;

	task = tasklist->head;
	while (task != NULL)
		if (task->id)
			return task;
	return NULL;
}
