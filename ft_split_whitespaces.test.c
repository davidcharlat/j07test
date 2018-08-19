#include<stdio.h>
#include <stdlib.h>

char **ft_split_whitespaces(char *str);

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
	char	*str = "  hello world\n \tis\teverybody\nOK?     ";
	
	i = 0;
	tab = ft_split_whitespaces(str);
	printf("Since source strings is\n \"%s\", words should be \"hello\" \"world\" \"is\" \"everybody\" and \"OK?\"\n", str);
	assertStringEqual("hello", tab[0]);
	printf("1st word OK\n");
	assertStringEqual("world", tab[1]);
	printf("2nd word OK\n");
	assertStringEqual("is", tab[2]);
	printf("3rd word OK\n");
	assertStringEqual("everybody", tab[3]);
	printf("4th word OK\n");
	assertStringEqual("OK?", tab[4]);
	printf("5th word OK\n");
	printf("the new array must be termated by 0: ");
	assertPtrEqual(NULL, tab[5]);
	printf("OK\n");
	free (tab[-1]);
	free (tab-1);	
	return (0);
}
