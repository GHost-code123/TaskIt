#include "taskit.h"

const char	*file_suffix = "_tskit.txt";

void	save_user_tasklist(Tasklist *tasklist, const char *username)
{
	char	user_filename[31];
	FILE	*taskit_file;

	strcpy(user_filename, username);
	strcat(user_filename, file_suffix);
	printf(HYEL"Save this task list to "HRED"%s"HYEL" file ?"DFLT" [y / n]: ", user_filename);
	if (!confirm_prompt())
		return ;

	taskit_file = fopen(user_filename, "w");
	if (taskit_file == NULL) {
		fprintf(stderr, RED"Error: "DFLT"Can't open %s file\n", user_filename);
		perror("");
		return ;
	}
	for (Task *task = tasklist->head; task != NULL; task = task->next)
		show_task_details(task, taskit_file);

	fclose(taskit_file);
}

// void	import_tasklist(Tasklist *tasklist, const char *username)
// {
// 	char	user_filename[31];
// 	FILE	*taskit_file;

// 	strcpy(user_filename, username);
// 	strcat(user_filename, file_suffix);

// 	printf(HYEL"You want to import the task list of this user if it exist ?"DFLT" [y / n]: ");
// 	if (!confirm_prompt())
// 		return ;
	
// 	taskit_file = fopen(user_filename, "r");
// 	if (taskit_file == NULL) {
// 		fprintf(stderr, RED"Error: "DFLT"Can't open %s file\n", user_filename);
// 		perror("");
// 		return ;
// 	}

	
// }
