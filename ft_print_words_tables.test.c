#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char **ft_split_whitespaces(char *str);
void ft_print_words_tables(char **tab);

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int     main()
{
	char str[] = " yo \t\n I'm fine.   'cause my job's OK !\n:)\t:D ";
	char **tab;
	tab = ft_split_whitespaces(str);
	printf("Source string is:\n\"%s\"\nft_print_words_tables(Source) do:\n", str);
	ft_print_words_tables(tab);
	free (tab[-1]);
	free (tab-1);
	return (0);
}
