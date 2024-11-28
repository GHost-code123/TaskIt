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

	printf(BHYEL"%s\n"DFLT
		"%.20s%.58s\n"
		"%.20s*                                                        *\n"
		"%.20s*                 "BHMAG">>>    TaskIt  📝  <<<"DFLT"                 *\n"
		"%.20s*                "HBLU"%.24s"DFLT"                *\n"
		"%.20s*                                                        *\n"
		"%.20s*   "YEL"Welcome  "HCYN"%*s%*s"YEL" to your task manager"DFLT"   *\n"
		"%.20s%.58s\n\n",
		bold_line, blank, star_bord, blank, blank,
		blank, get_curtime(), blank, blank, 10 + pad, username,
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
		"   2 - Show tasks details (with filter)\n"
		"   3 - Edit a task\n"
		"   4 - Delete a task or more\n"
		"   5 - Show tasks list (with filter)\n"
		"   6 - Sort tasks list\n"
		"   0 - Back to main menu\n\n"
		);
}

void	show_tasks_table(Tasklist *tasklist, int stat_filt, int prior_filt)
{
	const char	*prior_color[] = {"🟡", "🟠", "🔴"};

	printf( "╔═══════╦════════════════════════════════════════════════════╦════════╦══════════════╦════════════╗\n"
			"║    "HGRN"ID"DFLT" ║                       "HGRN"Title"DFLT"                        ║ "
			 HGRN"Status"DFLT" ║   "HGRN"Priority"DFLT"   ║  "HGRN"Due date"DFLT"  ║\n");

	for (Task *task = tasklist->head; task != NULL; task = task->next)
	{
		if (stat_filt != -1 && stat_filt != task->stat)
			continue ;
		if (prior_filt != -1 && prior_filt != task->priority)
			continue ;
		printf("╠═══════╬════════════════════════════════════════════════════╬════════╬══════════════╬════════════╣\n"
				"║ %5d ║ %-50.50s ║   %s   ║  %s  %-6s  ║ %s ║\n",
				task->id, task->title, task->stat == COMPLETED ? "✅" : "❌",
				prior_color[task->priority], priorities[task->priority], task->duedate);
	}
	printf( "╠═══════╩════════════════════════════════════════════════════╩════════╩══════════════╩════════════╣\n"
			"║             Total: %-5zu              Completed: %-5d              Incompleted: %-5d          ║\n"
			"╚═════════════════════════════════════════════════════════════════════════════════════════════════╝\n",
			tasklist->size, tasklist->compl_tasks, tasklist->incompl_tasks);
}

void	ask_to_continue()
{
	usleep(700000);
	printf(HYEL"\n\t\t( Press ENTER to go back to menu )"DFLT);
	(void)getchar();
}

int	confirm_prompt()
{
	char r;

	scanf(" %c", &r);

	clear_stdin();
	if (tolower(r) == 'y')
		return 1;

	return 0;
}
