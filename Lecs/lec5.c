#include <stdio.h>
#include <stdlib.h>

struct student_record{ //struct defines a new data structure.
    //name of variables are "fields"
    int esc180;
    int phy180;
};

void f(struct student_record s){
    s.esc180 = 100;
    //does not actually modify
}
void g(int *a){
    *a = 100;
}
void h(struct student_record *ps){
    (*ps).esc180 = 50; //() for precendence (*ps) = s1
    ps->phy180 = 100;  //-> is the same as (*ps).
}

int *make_arr(int size){
    //allocates for an array of ints of size elements, returns pointer to first element
    return (int *)malloc(size * sizeof(int));
}

int main(void){
    struct student_record s1 = {75, 70};
    printf("%ld\n", sizeof(struct student_record));         // = 2*int
    printf("%ld\t%ld\t%ld\n", &s1, &s1.esc180, &s1.phy180); //&s1 = address of first element

    printf("%d\t%d\n", s1.esc180, s1.phy180);
    f(s1); //does not modify the values in main.
    printf("%d\t%d\n", s1.esc180, s1.phy180);
    g(&s1.esc180); // modifies the value in main, same as passing a plain int.
    printf("%d\t%d\n", s1.esc180, s1.phy180);
    h(&s1); //also modifies the vvalues, references the stucture, not just one element
    printf("%d\t%d\n", s1.esc180, s1.phy180);

    int x = 5;
    float y = (float)x; //converting types

    long int add = (long int)(&s1);
    printf("%ld\n", add);

    int *a1 = (int *)malloc(10 * sizeof(int)); //allocate memory (type void*), then cast to int *
    //a now points to an array of length 10
    a1[5] = 10;

    int *a2 = make_arr(5); //dynamically allocate arrays.
    a2[1] = 10;

    return 0;
}