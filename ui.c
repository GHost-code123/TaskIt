#include "taskit.h"


static const char	*star_bord = "*************************"
								"******************************************"
								"*********************************";
static const char	*blank = "                               "
							"                                 "
							"                                    ";

static const char *bold_line = "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
								"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";

void	show_banner(const char *username)
{
	const int		pad = (int)strlen(username) / 2;
	const time_t	tm = time(NULL);

	printf(BHYEL"%s\n"DFLT
		"%.20s%.58s\n"
		"%.20s*                                                        *\n"
		"%.20s*                 "BHMAG">>>    TaskIt  📝  <<<"DFLT"                 *\n"
		"%.20s*                "HBLU"%.24s"DFLT"                *\n"
		"%.20s*                                                        *\n"
		"%.20s*   "YEL"Welcome  "HCYN"%*s%*s"YEL" to your task manager"DFLT"   *\n"
		"%.20s%.58s\n\n",
		bold_line, blank, star_bord, blank, blank,
		blank, ctime(&tm), blank, blank, 10 + pad, username,
		10 - pad, "", blank, star_bord);
}

void	show_main_menu()
{
	printf(BHGRN"\nMain menu: "HYEL"───────────────\n"DFLT
			"   m - Manage tasks\n"
			"   t - Show tasks list\n"
			"   s - Save this task list\n"
			"   u - Change/Add user\n"
			"   q - Exit\n\n"
			);
}

void	show_tskmng_menu()
{
	printf(BLU"\nTask management menu: "HYEL"───────────────\n"DFLT
		"   1 - Add a task\n"
		"   2 - Show tasks details\n"
		"   3 - Edit a task\n"
		"   4 - Delete a task or more\n"
		"   5 - Show tasks list\n"
		"   0 - Back to main menu\n\n"
		);
}

void	show_tasks_table(Tasklist *tasklist, int show_options, int show_more)
{

	printf( "╔═════╦════════════════════════════════════════════════════╦════════╦══════════╦════════════╗\n"
			"║  "HGRN"ID"DFLT" ║                       "HGRN"Title"DFLT"                        ║ "
			 HGRN"Status"DFLT" ║ "HGRN"Priority"DFLT" ║  "GRN"Due date"DFLT"  ║\n");
	if (tasklist->size == 0)
		printf("╠═════╬════════════════════════════════════════════════════╬════════╬══════════╬════════════╣\n");
	else {
		for (Task *task = tasklist->head; task != NULL; task = task->next)
		{
			printf("╠═════╬════════════════════════════════════════════════════╬════════╬══════════╬════════════╣\n"
					"║%5d║ %-50s ║   %s   ║%10c║ %s ║\n",
					task->id, task->title, task->stat == COMPLETED ? "✅" : "❌", task->priority, task->duedate);
		}
	}
	printf("╚═════╩════════════════════════════════════════════════════╩════════╩══════════╩════════════╝\n");
}

void	ask_to_continue()
{
	usleep(700000);
	printf(HYEL"\n\t\t( Press ENTER to go back to menu )"DFLT);
	(void)getchar();
}
