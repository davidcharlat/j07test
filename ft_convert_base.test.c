#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

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
	char	*result1 = "400";
	char	*nbr1 = "1024";
	char	*from1 = "0123456789";
	char	*to1 = "0123456789abcdef";
	char	*result;
	
	result = ft_convert_base(nbr1, from1, to1);
	printf("Since source strings are\n nbr:\"%s\" base from\"%s\" base to\"%s\"\nresult should be\n\"%s\"\n", nbr1, from1, to1 , result1); 
	assertStringEqual(result1, result);
	printf("OK\n");
	free (result);
	return(0);
}
