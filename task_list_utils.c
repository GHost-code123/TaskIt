#include "taskit.h"

static char	get_valid_priority()
{
	char	c;

	while (1)
	{
		scanf(" %c", &c);
		switch (toupper(c))
		{
		case 'L':
		case 'M':
		case 'H':
			return c;

		default:
			printf(RED"%c is an invalid input\n"
					HYEL"Please choose a valid input 'H' (High), "
					"'M' (Medium), 'L' (Low): "DFLT, c);
			break ;
		}
		clearerr(stdin);
	}
}

static void	set_date(char *buf)
{
	struct tm	date;

	do {
		scanf(" %2d-%2d-%4d", &date.tm_mday, &date.tm_mon, &date.tm_year);
		clear_stdin();
		
		if (isvalid_date(&date))
			break ;
		clearerr(stdin);

		printf(RED"Date is not valid\n"
				YEL"Please enter a valid date (format: dd-mm-yyyy): "DFLT);
	} while (1);

	strftime(buf, 13, "%d-%m-%Y", &date);
}

Task	*task_new(int id)
{
	Task	*task;
	char	*desc = NULL;

	task = malloc(sizeof(*task));
	if (task == NULL)
		return NULL;

	printf(HYEL"> Enter task title (character limit: 50): "DFLT);
	get_s(task->title, sizeof(task->title));

	printf(HYEL"> Type task description (Ctrl-D if done):\n"DFLT);
	task->desc = NULL;
	while (get_line(&desc) != -1)
		task->desc = strjoin(task->desc, desc);

	printf(HYEL"> Enter task priority 'H': High, 'M': Medium, 'L': Low (one character): "DFLT);
	task->priority = get_valid_priority();

	printf(HYEL"> Enter task due date (dd-mm-yyyy): "DFLT);
	set_date(task->duedate);

	task->id = id;
	task->stat = INCOMPLETED;
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

void	edit_task()
{

}

