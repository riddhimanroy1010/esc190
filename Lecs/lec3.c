#include <stdio.h>

void f(int a[]);
void f2(int *a);

int main(int agrc, char* argv[])
{
    int a[3] = {2, 3, 4}; //arrays in C are predetermined in size and order
    printf("%d \n", a[1]);

    //can use arrays as pointers to the first array
    printf("%d \n", *a); //first element

    int* p_a = &a[0];
    printf("%d, %d, %d \n", p_a, p_a + 1, p_a + 2);

    f2(a);
    //a[1] = *(a + 1) and so on for other things true for any data types
    printf("%d \n", *(a + 1));

    a[1] = 3;
    f(a);
    printf("%d \n", a[1]);
    
    printf("An int takes %d bytes in memory \n", sizeof(int));
    printf("Other data types take the following amount of storage:\n");
    printf("char: %d \n", sizeof(char));
    printf("Double: %d", sizeof(double));
    
    return 0;
}

void f(int a[])
{
    a[0] = 5; //same as a* = 5
    a[1] = 7;
}
//these two functions are identical; an array is a pointer to the first element in the array
void f2(int *a)
{
    *a = 5; //same as a[0] = 5
    *(a + 1) = 7;
}