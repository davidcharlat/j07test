#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str, char *charset);

void    assertStringEqual(char *expected, char *received)
{
   int cursor;

	cursor = 0;
	while (*(expected + cursor) != '\0' && *(expected + cursor) == *(received + cursor))
			cursor++;
	if (*(expected + cursor) != *(received + cursor))
	{
	        fprintf(stderr, "STRING_NOT_EQUAL : expecting \"%s\" - received \"%s\".\n", expected, received);
	        exit(1);
	}
}

void    assertPtrEqual(void* expected, void* received)
{
    if (expected != received)
    {
        fprintf(stderr,"PTR_NOT_EQUAL : expecting %p - received %p.\n", expected, received);;
        exit(1);
    }
}

int     main()
{
	int		i;
	char	**tab;
	char	**tab2;
	char	*charset = "yes or no";
	char	*str = "  hello world\n yes or no is everybodyes or yes or noyes or noOK? yes or no";
	char	*str2 = "yes or no yes or no";
	
	i = 0;
	tab = ft_split(str, charset);
	printf("Since source strings is :\n\"%s\" and charset:\n\"%s\", words should be \"  hello world\n \" \" is everybodyes or \" and \"OK? \"\n", str, charset);
	assertStringEqual("  hello world\n ", tab[0]);
	printf("1st word OK\n");
	assertStringEqual(" is everybodyes or ", tab[1]);
	printf("2nd word OK\n");
	assertStringEqual("OK? ", tab[2]);
	printf("3th word OK\n");
	printf("the new array must be termated by 0: ");
	assertPtrEqual(NULL, tab[3]);
	printf("OK\n");
	while (i <= 3)
		free (tab[i++]);
	free (tab);
	tab2 = ft_split(str2, charset);
	printf("Since source strings is :\n\"%s\" and charset:\n\"%s\", word should be \" \"\n", str2, charset);
	assertStringEqual(" ", tab2[0]);
	printf("OK\n");
	i = 0;
	while (i <= 1)
		free (tab2[i++]);
	free (tab2);
	return (0);
}
