#include <stdio.h>

void printer(int f[], int len);


struct student_record
{
    int esc180_mark;
    int phy180_mark;
};


int main(void)
{
    int size = 3;
    int a[3] = {4, 5, 6};
    printer(a, 3);
    printf("\n");

    struct student_record student1;
    student1.esc180_mark = 85;
    student1.phy180_mark = 82;
    printf("%ld", sizeof(struct student_record));


    return 0;
}

void printer(int f[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", f[i]);
    }
}
