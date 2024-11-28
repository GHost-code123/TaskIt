#include "taskit.h"

const char	*priorities[] = {"Low", "Medium", "High"};

static Prior	get_valid_priority()
{
	char	c;

	while (1)
	{
		c = get_char();
		switch (toupper(c))
		{
		case 'L':
			return LOW;
		case 'M':
			return MED;
		case 'H':
			return HIGH;

		default:
			printf(RED"%c is an invalid input\n"
					HYEL"Please choose a valid input 'H' (High), "
					"'M' (Medium), 'L' (Low): "DFLT, c);
			break ;
		}
	}
	return LOW;
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

	date.tm_year -= 1900;
	date.tm_mon -= 1;
	strftime(buf, 13, "%d-%m-%Y", &date);
}

void	add_task(Tasklist *tasklist)
{
	Task	*task;
	char	*desc = NULL;

	task = tasklist_new();
	if (task == NULL)
		fatal_error(tasklist);

	printf(HYEL"> Enter task title (character limit: 50): "DFLT);
	get_s(task->title, sizeof(task->title) - 1);

	printf(HYEL"> Type task description (Ctrl-D if done):\n"DFLT);
	task->desc = NULL;
	while (get_line(&desc) != -1)
	{
		task->desc = strjoin(task->desc, desc);
		free(desc);
		desc = NULL;
		if (task->desc == NULL)
			fatal_error(tasklist);
	}
	free(desc);

	printf(HYEL"> Enter task priority 'H': High, 'M': Medium, 'L': Low (one character): "DFLT);
	task->priority = get_valid_priority();

	printf(HYEL"> Enter task due date (dd-mm-yyyy): "DFLT);
	set_date(task->duedate);

	task->stat = INCOMPLETED;
	task->id = tasklist->size;
	task->creattime = get_curtime();
	task->modiftime = "\n";
	tasklist_add(tasklist, task);
}

void	show_task_details(Task *task, FILE *stream)
{
	const char *status[] = {"Completed", "Incomleted"};

	fprintf(stream, "Task %d:\n- Title: %s\n- Description:\n%s\n"
					"- Status: %s\n- Priority: %s\n"
					"- Due date: %s\n- Created: %s- Modified: %s\n---\n\n",
					task->id, task->title, task->desc, status[task->stat],
					priorities[task->priority], task->duedate,
					task->creattime, task->modiftime);
}

void	show_task(Tasklist *tasklist, int stat_filt, int prior_filt)
{
	int		id=0, idn=-1;
	char	s[12];
	Task	*task;

	printf(HYEL"> Enter task id or an ids range (d-d e.g 0-9) or '*' for all: "DFLT);
	get_s(s, 12);

	if (tasklist->size == 0) {
		printf("Task list is empty !\n");
		ask_to_continue();
		return ;
	}

	if (s[0] == '*' && s[1] == '\0')
	{
		id = 0;
		idn = tasklist->size;
	}
	else
		sscanf(s, "%5d-%5d", &id, &idn);

	if (id >= tasklist->size) {
		printf(RED"Task of this id doesn't exist !\n"DFLT);
		ask_to_continue();
		return ;
	}
	task = get_task_byId(tasklist, id);
	for (; task != NULL; task = task->next)
	{
		if (stat_filt != -1 && stat_filt != task->stat)
			continue ;
		if (prior_filt != -1 && prior_filt != task->priority)
			continue ;
		show_task_details(task, stdout);
		if (task->id == idn)
			break;
	}
	ask_to_continue();
}

void	show_filt_task(Tasklist *tasklist)
{
	int	stat_filt = -1;
	int	prior_filt = -1;

	printf(HYEL"> Filter task by status ?"DFLT" [y / n]: ");
	if (confirm_prompt()) {
		printf(YEL"Choose filter (0) Incompleted (1) Completed : "DFLT);
		scanf(" %d", &stat_filt);
		if (stat_filt != 0 && stat_filt != 1)
			stat_filt = -1;
	}
	printf(HYEL"> Filter task by priority ?"DFLT" [y / n]: ");
	if (confirm_prompt()) {
		printf(YEL"Choose filter (0) Low (1) Medium (2) High : "DFLT);
		scanf(" %d", &prior_filt);
		if (prior_filt != 0 && prior_filt != 1 && prior_filt != 2)
			prior_filt = -1;
	}

	show_task(tasklist, stat_filt, prior_filt);
}

void	edit_task(Tasklist *tasklist)
{
	int		id;
	Task	*task;
	char	*desc = NULL;

	printf(HYEL"> Enter the id of the task to edit: "DFLT);
	scanf(" %d", &id);
	clear_stdin();

	task = get_task_byId(tasklist, id);
	if (task == NULL) {
		printf(RED"Task of this id doesn't exist !\n"DFLT);
		ask_to_continue();
		return ;
	}

	printf(HRED"Change the current task title (%s) ?"DFLT" [y / n]: ", task->title);
	if (confirm_prompt()) {
		printf(HYEL"> Enter a new title: "DFLT);
		get_s(task->title, sizeof(task->title) - 1);
	}
	printf(HRED"Change the current description ?"DFLT" [y / n]: ");
	if (confirm_prompt()) {
		free(task->desc);
		task->desc = NULL;
		printf(HYEL"> Type a new description (Ctrl-D if done):\n"DFLT);
		while (get_line(&desc) != -1)
		{
			task->desc = strjoin(task->desc, desc);
			if (task->desc == NULL)
				fatal_error(tasklist);
		}
	}
	printf(HRED"Change the current task priority (%s) ?"DFLT" [y / n]: ", priorities[task->priority]);
	if (confirm_prompt()) {
		printf(HYEL"> Enter a new priotity 'H': High, 'M': Medium, 'L': Low (one character): "DFLT);
		task->priority = get_valid_priority();
	}
	printf(HRED"Change the current task due date (%s) ?"DFLT" [y / n]: ", task->duedate);
	if (confirm_prompt()) {
		printf(HYEL"> Enter a new priotity due date (dd-mm-yyyy): "DFLT);
		set_date(task->duedate);
	}
	printf(HRED"Is the task completed ?"DFLT" [y / n]: ");
	if (confirm_prompt() && task->stat == INCOMPLETED) {
		task->stat = COMPLETED;
		tasklist->compl_tasks++;
		tasklist->incompl_tasks--;
	}
	else if (task->stat == COMPLETED) {
		task->stat = INCOMPLETED;
		tasklist->incompl_tasks++;
		tasklist->compl_tasks--;
	}

	task->modiftime = get_curtime();
}

void	delete_task(Tasklist *tasklist)
{
	int		id;
	Task	*task;

	printf(HYEL"> Enter the id of the task to delete: "DFLT);
	scanf(" %d", &id);
	clear_stdin();

	task = get_task_byId(tasklist, id);
	if (task == NULL) {
		printf(RED"Task of this id doesn't exist !\n"DFLT);
		ask_to_continue();
		return ;
	}

	printf(BHRED"Are you sure you want to delete task(%d) '%s' ?"DFLT" [y / n]: ", id, task->title);
	if (confirm_prompt()) {
		tasklist_del(tasklist, task);
		printf(HGRN"Task deleted!\n");
		ask_to_continue();
	}
}

void	show_filt_tasks_table(Tasklist *tasklist)
{
	int	stat_filt = -1;
	int	prior_filt = -1;

	printf(HYEL"> Filter task by status ?"DFLT" [y / n]: ");
	if (confirm_prompt()) {
		printf(YEL"Choose filter (0) Incompleted (1) Completed : "DFLT);
		scanf(" %d", &stat_filt);
		if (stat_filt != 0 && stat_filt != 1)
			stat_filt = -1;
	}
	printf(HYEL"> Filter task by priority ?"DFLT" [y / n]: ");
	if (confirm_prompt()) {
		printf(YEL"Choose filter (0) Low (1) Medium (2) High : "DFLT);
		scanf(" %d", &prior_filt);
		if (prior_filt != 0 && prior_filt != 1 && prior_filt != 2)
			prior_filt = -1;
	}

	show_tasks_table(tasklist, stat_filt, prior_filt);
}

void	sort_task_list(Tasklist *tasklist)
{
	int option;

	printf(HYEL"> Choose how to sort tasks list: \n"DFLT
				"  1 - By ID in ascending order (Default)\n"
				"  2 - By ID in descending order\n"
				"  3 - By Priority from high to low\n"
				"  4 - By Priority from low to high\n"
				"  5 - By Due date from recent to oldest\n"
				"  6 - By Due date from oldest to recent\n"
				"  0 - Back to manage menu\n\n");
	
	printf(YEL"Enter your option: "DFLT);
	scanf(" %d", &option);
	clear_stdin();

	if (tasklist->size == 0) {
		printf("Task list is empty !\n");
		ask_to_continue();
		return ;
	}

	switch (option)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
		tasklist_sort_byPriority(tasklist);
		printf(HGRN"Task list is sorted from high to low!\n"DFLT);
		break;
	case 4:
		
		break;
	case 5:
		
		break;
	case 6:
		
		break;
	case 0:
		return ;
	
	default:
		printf(BRED"\nInvalid option!\n"DFLT);
		break;
	}
	ask_to_continue();
}


void	manage_tasks(Tasklist *tasklist)
{
	int	option;

	do {
		show_tskmng_menu();
		printf(YEL"Enter your option: "DFLT);
		scanf(" %d", &option);
		clear_stdin();

		switch (option)
		{
		case 1:
			add_task(tasklist);
			break;
		case 2:
			show_filt_task(tasklist);
			break;
		case 3:
			edit_task(tasklist);
			break;
		case 4:
			delete_task(tasklist);
			break;
		case 5:
			show_filt_tasks_table(tasklist);
			break;
		case 6:
			sort_task_list(tasklist);
			break;
		case 0:
			return ;

		default:
			printf(BRED"\nInvalid option! Please, choose a valid option.\n"DFLT);
			ask_to_continue();
			break;
		}
		
	} while (99);
}
