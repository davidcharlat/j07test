#include <stdio.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max);

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
    int test1;
    int test2;
    
    test2 = ft_ultimate_range(&tab2,-3,-3);
    printf("Since min is -3 and max -3, range should point to NULL\n");
    assertPtrEqual(NULL,tab2);
    printf("OK\n");
    printf("Since min is -3 and max -3, 0 should be returned\n");
    assertIntEqual(0,test2);
    printf("OK\n");
 
    test1 = ft_ultimate_range(&tab1,-3,1);
    printf("Since min is -3 and max 1, *range[0] should be -3\n");
    assertIntEqual(-3, tab1[0]);
    printf("OK\n");
    printf("Since min is -3 and max 1, *range[3] should be 0\n");
    assertIntEqual(0, tab1[3]);
    printf("OK\n");
    printf("Since min is -3 and max 1, 4 should be returned\n");
    
    assertIntEqual(4, test1);
    printf("OK\n");
    free(tab1);
    return (0);
}
