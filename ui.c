#include "taskit.h"

static const char	*star_bord = "*************************"
								"******************************************"
								"*********************************";
static const char	*blank = "                               "
							"                                 "
							"                                    ";

void	show_banner(const char *username)
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

void	show_main_menu()
{
	printf("+-"BHGRN" Main menu: "DFLT"--------------------+\n"
			"|                               |\n"
			"|   (m) Manage tasks            |\n"
			"|   (s) Save this task list     |\n"
			"|   (u) Change/Add user         |\n"
			"|   (q) Exit                    |\n"
			// "|                                 |\n"
			"+-------------------------------+\n"
			);
}
