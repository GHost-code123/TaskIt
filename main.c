#include "taskit.h"

static void	set_username(char *username)
{
	printf("Enter your name (max length: 20): ");
	scanf(" %20[^\n]", username);
	clear_stdin();
}

int	main()
{
	int			option;
	char		username[21] = "Lionel Messi";
	Tasklist	tasklist = {0, NULL, NULL};

	set_username(username);

	show_banner(username);
	show_tasks_table(&tasklist, 0, 0);

	do {
		show_main_menu();
		printf(YEL"Enter your option: "DFLT);
		option = get_char();

		switch (tolower(option))
		{
		case 'm':
			manage_tasks(&tasklist);
			break;
		case 't':
			show_tasks_table(&tasklist, 0, 1);
			break;
		case 's':
			
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
			ask_to_continue();
			break;
		}
	} while (42);

	return 0;
}
