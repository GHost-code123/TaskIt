#include "taskit.h"
#include <errno.h>

void	free_task(Task *task)
{
	free(task->desc);
	free(task);
}

void	free_tasklist(Tasklist *tasklist)
{
	Task	*tmp;
	Task	*task;

	task = tasklist->head;
	while (task != NULL)
	{
		tmp = task->next;
		free_task(task);
		task = tmp;
	}
}

void	fatal_error(Tasklist *tasklist)
{
	free_tasklist(tasklist);
	fprintf(stderr, RED"fatal error: "DFLT"%s\n", strerror(errno));
	exit(1);
}

void	exit_app(Tasklist *tasklist)
{
	free_tasklist(tasklist);
	printf(HGRN"\nBye !\n"DFLT);
	exit(0);
}
