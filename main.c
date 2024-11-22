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

int	main()
{
	char	username[21];

	printf("Enter your name (max length: 20): ");
	get_s(username, sizeof(username) - 1);

	show_banner(username);

	return 0;
}
