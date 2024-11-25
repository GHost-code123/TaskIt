#ifndef TASKIT_H
# define TASKIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "color.h"

# include "color.h"

typedef struct {
	char	title[51];
	char	*desc;
	char	priority; // Possoble values: 'H' (High), 'M' (Medium), 'L' (Low)
	char	duedate[11];
}	Task;

void	manage_tasks();

// Utils:
char	*strjoin(char *s1, char *s2);
char	*get_s(char *s, size_t n);
int		get_line(char **s);
int		get_char();
void	clear_stdin();


#endif /* TASKIT_H */
