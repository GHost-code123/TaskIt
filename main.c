#include "taskit.h"

static void	ask_to_continue()
{
	usleep(700000);
	printf(HYEL"\n\t\t( Press ENTER to show main menu )"DFLT);
	(void)getchar();
}

int	main()
{
	int			option;
	char		username[21] = "john Dike";
	Tasklist	task_list = {0, NULL, NULL};

	// printf("Enter your name (max length: 20): ");
	// get_s(username, sizeof(username));

	show_banner(username);

	do {
		show_main_menu();
		printf(HYEL"> Enter your option: "DFLT);
		option = get_char();
		// option = 'm';

		switch (option)
		{
		case 'm':
			// manage_tasks();
			add_task(&task_list);
			break;
		case 's':
			// Save task list
			break;
		case 'u':
			// Change/Add user
			break;
		case 'q':
			printf(HGRN"\nBye !\n"DFLT);
			exit(0);
			break;

		default:
			printf(BRED"\nInvalid option! Please, choose a valid option.\n"DFLT);
			break;
		}

		ask_to_continue();
	} while (69);

	return 0;
}
