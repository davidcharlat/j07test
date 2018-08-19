#include <stdio.h>
#include <stdlib.h>

int		*ft_range(int min, int max);

void    assertIntEqual(int expected, int received)
{
    if (expected != received)
    {
        fprintf(stderr, "INTEGER_NOT_EQUAL : expecting %d - received %d.\n", expected, received);
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
    int *tab1;
    int *tab2;
    
    tab1 = ft_range(-3,1);
    printf("Since min is -3 and max 1, ft_range[0] should be -3\n");
    assertIntEqual(-3, tab1[0]);
    printf("OK\n");
    printf("Since min is -3 and max 1, ft_range[3] should be 0\n");
    assertIntEqual(0, tab1[3]);
    printf("OK\n");
    free(tab1);
    tab2 = ft_range(-3,-3);
    printf("Since min is -3 and max -3, ft_range should point to NULL\n");
    assertPtrEqual(tab2,NULL);
    printf("OK\n");
    free(tab2);
    return (0);
}
