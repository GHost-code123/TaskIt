#include "taskit.h"

char	*strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s1)
		return (strdup(s2));
	len = strlen(s1) + strlen(s2);

	str = malloc(len + 1);
	if (!str)
		return NULL;

	strcpy(str, s1);
	free(s1);
	strcat(str, s2);

	return str;
}

int	get_line(char **s)
{
	size_t	n = 0;

	if (getline(s, &n, stdin) < 0) {
		clearerr(stdin);
		return -1;
	}

	return 0;
}

char	*get_s(char *s, size_t n)
{
	char	*p;

	*s = 0;
	while (isspace((*s = getchar())));

	fgets(s + 1, n - 1, stdin);

	p = strrchr(s, '\n');
	if (p)
		*p = 0;
	else
		clear_stdin();
	return s;
}

char	get_char()
{
	char	c;

	scanf(" %c", &c);
	clear_stdin();
	return c;
}

void	clear_stdin()
{
	int	c;

	while ((c = getchar()) != '\n' && c != EOF);
	clearerr(stdin);
}
