#include <stdio.h>


void swap_pointers(int *p_a, int *p_b);
void swap(int a, int b);

int main(void)
{
    int a = 5;
    int b = 6;
    int* p_a = &a; //address of a
    printf("%ld \n", p_a);

    printf("Swapping pointers \n");
    swap_pointers(&a, &b); //exchanging pointers of a and b; not actually overwriting them
    printf("%i, %i \n", a, b);

    a = 5;
    b = 6;

    printf("swapping values \n");
    swap(a, b); //cant overwrite so yeh pointer good
    printf("%i, %i \n", a, b);

    int* *pp_a = &p_a; //address of the address of a; you can basically keep going
    printf("address of p_a: %i\n", pp_a);
    return 0;
}

void swap_pointers(int *p_a, int *p_b)
{
    int temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}