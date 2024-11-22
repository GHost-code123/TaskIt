#include "taskit.h"

char	*get_s(char *s, size_t n)
{
	char	*p;

	fgets(s, n, stdin);

	p = strrchr(s, '\n');
	if (p) {
		printf("here\n");
		*p = 0;
	} else {
		clear_stdin();
	}

	return s;
}

void	clear_stdin()
{
	int	c;

	while ((c = getchar()) != '\n' && c != EOF);
}
