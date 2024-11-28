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
	tasklist->size++;
	tasklist->incompl_tasks++;
	if (tasklist->head == NULL) {
		tasklist->head = newtask;
		tasklist->tail = newtask;
		return ;
	}
	newtask->prev = tasklist->tail;
	tasklist->tail->next = newtask;
	tasklist->tail = newtask;
}

void	tasklist_del(Tasklist *tasklist, Task *task)
{
	if (tasklist->head == task)
		tasklist->head = task->next;
	if (tasklist->tail == task)
		tasklist->tail = task->prev;
	tasklist->size--;
	if (task->stat == COMPLETED)
		tasklist->compl_tasks--;
	else
		tasklist->incompl_tasks--;

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
	{
		if (task->id == id)
			return task;
		task = task->next;
	}
	return NULL;
}


// /////////// Bubble sort /////

static void	swap_next(Tasklist *tasklist, Task *task)
{
	Task *next;

	if (tasklist->size == 1)
		return ;
	
	if (task == tasklist->head)
		tasklist->head = task->next;

	next = task->next;
	task->next = next->next;
	next->prev = task->prev;
	task->prev = next;
	next->next = task;
}

void	tasklist_sort_byId(Tasklist *tasklist)
{

}

void	tasklist_sort_byPriority(Tasklist *tasklist)
{
	int		swapped;
	Task	*ptr;
	Task	*lptr = NULL;

	if (tasklist->size < 2)
		return ;

	do
	{
		swapped = 0;
		ptr = tasklist->head;

		while (ptr->next != lptr)
        {
    		if (ptr->priority > ptr->next->priority)
			{
				swap_next(tasklist, ptr);
				swapped = 1;
				continue ;
			}
			ptr = ptr->next;
        }
		printf("here\n");
		lptr = ptr;
	}
	while (swapped);
}

void	tasklist_sort_byDate(Tasklist *tasklist)
{

}

///
