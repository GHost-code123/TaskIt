#include "taskit.h"

static void	set_username(char *username)
{
	printf("Enter your name (max length: 20): ");
	get_s(username, 21);
}

int	main()
{
	int			option;
	char		username[21] = "Lionel Messi";
	Tasklist	tasklist = {0, 0, 0, NULL, NULL};

start:
	set_username(username);

	show_banner(username);
	show_tasks_table(&tasklist, -1, -1);

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
			show_tasks_table(&tasklist, -1, -1);
			break;
		case 's':
			save_user_tasklist(&tasklist, username);
			break;
		case 'u':
			free_tasklist(&tasklist);
			goto start;
			break;
		case 'q':
			exit_app(&tasklist);
			break;

		default:
			printf(BRED"\nInvalid option! Please, choose a valid option.\n"DFLT);
			ask_to_continue();
			break;
		}
	} while (42);

	return 0;
}
