#include "taskit.h"

static const char	*star_bord = "*************************"
								"******************************************"
								"*********************************";
static const char	*blank = "                               "
							"                                 "
							"                                    ";

static void	show_banner(const char *username)
{
	const int	pad = (int)strlen(username) / 2;

	printf("\n"
		"%.20s%.58s\n"
		"%.20s*                                                        *\n"
		"%.20s*                 "BHMAG">>>    TaskIt  📝  <<<"DFLT"                 *\n"
		"%.20s*                                                        *\n"
		"%.20s*   "YEL"Welcome  "HCYN"%*s%*s"YEL" to your task manager"DFLT"   *\n"
		"%.20s%.58s\n",
		blank, star_bord, blank, blank,
		blank, blank,  10 + pad, username,
		10 - pad, "", blank, star_bord);
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
	char	username[21] = "john Dike";

	printf("Enter your name (max length: 20): ");
	get_s(username, sizeof(username));

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
