#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

void    assertStringEqual(char *expected, char *received)
{
   int cursor;

	cursor = 0;
	while (*(expected + cursor) != '\0' && *(expected + cursor) == *(received + cursor))
			cursor++;
	if (*(expected + cursor) != *(received + cursor))
	{
	        fprintf(stderr, "STRING_NOT_EQUAL : expecting %s - received %s.\n", expected, received);
	        exit(1);
	}
}

int     main()
{
	char src[] = "hello world";
	char *dest;

	dest = ft_strdup(src);
	printf("Since source string is \"%s\" , duplicated string should be \"%s\"\n", src, src);
	assertStringEqual(src, dest);
	printf("OK\n");
	free (dest);
	return (0);
}
