#include "taskit.h"

int	main()
{
	char s[100] = {1};
	char s1[100];
	char s2[100];
	char c;

	printf("1 here: ");
	scanf("%[^\n]", s);
	printf("2 here: ");
	// c = getchar();
	// printf("3 here: %d\n", c);
	scanf("\n%c", &c);
	printf("4 here: %d\n", c);


	printf("> %s|\n", s);
	printf("> %s|\n", s1);
	printf("> %s|\n", s2);

	return 0;
}
