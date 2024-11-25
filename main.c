#include "taskit.h"

static const char	*star_bord = "*************************"
								"******************************************"
								"*********************************";
static const char	*blank = "                               "
							"                                 "
							"                                    ";

static void	show_banner(const char *username)
{
	printf("\n"
		"%.20s%.40s\n" // upper border
		"%.20s*                 >>>    TaskIt    <<<                 *\n" // Taskit title
		"%.20s*  Welcome %20.20s to your task manager   *\n" // Welcome
		"%.30s%.40s\n", // lower border
		blank, star_bord,
		blank, blank, username,
		blank, star_bord);
}

static void	ask_to_continue()
{
	printf(HYEL"\n\t\t( Press ENTER to show main menu )"DFLT);
	(void)getchar();
}

static void	show_main_menu()
{
	printf(BHGRN"Main menu: "DFLT"----------------+\n"
			"|  (m) Manage tasks        |\n"
			"|  (s) Save this task list |\n"
			"|  (u) Change/Add user     |\n"
			"|  (q) Exit                |\n"
			);
}

int	main()
{
	int		option;

	// char	username[21];

	// printf("Enter your name (max length: 20): ");
	// get_s(username, sizeof(username) - 1);

	// show_banner(username);

	do {
		show_main_menu();
		printf(HYEL"> Enter your option: "DFLT);
		option = get_char();

		switch (option)
		{
		case 'm':
			manage_tasks();
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

		usleep(700000);
		ask_to_continue();
	} while (69);

	return 0;
}
