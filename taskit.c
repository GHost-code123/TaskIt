#include "taskit.h"

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
			// show_task_details
			break;
		case '3':
			// Edit task
			break;
		case '4':
			// Edit task
			break;
		case '5':
			// Edit task
			break;
		case 'q':
			return ;

		default:
			printf(BRED"\nInvalid option! Please, choose a valid option.\n"DFLT);
			ask_to_continue();
			break;
		}
		
	} while (99);
}
