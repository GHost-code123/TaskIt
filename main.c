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

int	main()
{
	char	username[21] = "john Dike";

	printf("Enter your name (max length: 20): ");
	get_s(username, sizeof(username));

	show_banner(username);

	return 0;
}
