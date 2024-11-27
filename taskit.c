#include "taskit.h"

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
					HYEL"Please choose a valid input 'H' (High), "
					"'M' (Medium), 'L' (Low): "DFLT, c);
			break ;
		}
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

		printf(RED"Date is not valid\n"
				YEL"Please enter a valid date (format: dd-mm-yyyy): "DFLT);
	} while (1);

	strftime(buf, 13, "%d-%m-%Y", &date);
}

void	add_task(Tasklist *tasklist)
{
	Task	*task;
	char	*desc = NULL;

	task = tasklist_new();
	if (task == NULL)
		fatal_error(tasklist);

	char t[51];
	printf(HYEL"> Enter task title (character limit: 50): "DFLT);
	get_s(t, sizeof(task->title) - 1);

	printf(HYEL"> Type task description (Ctrl-D if done):\n"DFLT);
	task->desc = NULL;
	while (get_line(&desc) != -1)
	{
		task->desc = strjoin(task->desc, desc);
		if (task->desc == NULL)
			fatal_error(tasklist);
	}

	printf(HYEL"> Enter task priority 'H': High, 'M': Medium, 'L': Low (one character): "DFLT);
	task->priority = get_valid_priority();

	printf(HYEL"> Enter task due date (dd-mm-yyyy): "DFLT);
	set_date(task->duedate);

	task->stat = INCOMPLETED;
	task->id = tasklist->size;
	tasklist_add(tasklist, task);
}

void	show_task(Tasklist *tasklist)
{
	int	id, idn;

	printf(HYEL"> Enter task id or an ids range (d-d e.g 0-9) or -1 for all: ");
	scanf("");
	
}

// 1234567890123456789012345678901234567890123456789l

void	edit_task(Tasklist *tasklist)
{
	
}

void	delete_task(Tasklist *tasklist)
{

}

void	manage_tasks(Tasklist *tasklist)
{
	int	option;

	do {
		show_tskmng_menu();
		printf(YEL"Enter your option: "DFLT);
		option = get_char();

		switch (tolower(option))
		{
		case '1':
			add_task(tasklist);
			break;
		case '2':
			show_task(tasklist);
			break;
		case '3':
			edit_task(tasklist);
			break;
		case '4':
			delete_task(tasklist);
			break;
		case '5':
			show_tasks_table(tasklist, 1, 1);
			break;
		case '0':
			return ;

		default:
			printf(BRED"\nInvalid option! Please, choose a valid option.\n"DFLT);
			ask_to_continue();
			break;
		}
		
	} while (99);
}
