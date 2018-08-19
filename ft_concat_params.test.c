#include <stdio.h>
#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv);

void    assertStringEqual(char *expected, char *received)
{
   int cursor;

	cursor = 0;
	while (*(expected + cursor) != '\0' && *(expected + cursor) == *(received + cursor))
			cursor++;
	if (*(expected + cursor) != *(received + cursor))
	{
	        fprintf(stderr, "STRING_NOT_EQUAL : expecting \n%s - received\n %s.\n", expected, received);
	        exit(1);
	}
}

int     main(int argc, char **argv)
{
	char *dest;
	char result[] = "firststring\nstring2\n3rd str\n";
	
	dest = ft_concat_params(argc, argv);
	printf("Since source strings are\n \"%s\" \"%s\" \"%s\"\nduplicated string should be\n\"%s\"\n", argv[1],argv[2],argv[3], result);
	assertStringEqual(result, dest);
	printf("OK\n");
	free (dest);
	return (0);
}
