#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = -8;
    int b = 1;
    printf("%i \n");
    if (a > 2)
    {
        printf("true");
    }
    else if (a < 0)
    {
        printf("false");
    }
    else
    {
        return 1;
    }

    // Type: pointer
    int *p_a = &a; //pointing p_a to the address of a, with &. & means address of
    printf("%ld \n", p_a);

    return 0;
}


