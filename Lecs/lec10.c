#include <stdio.h>

typedef float my_float;

typedef struct node
{
    int data;
    struct node* next;
} node;

int main(void)
{
    my_float c = 3.14;
    const int a = 5; //cannot modify this value

    //big brain play
    int* b = (int*)&a;
    *b = 4;
    printf("%d", a);
    //done

    node n1; 
    n1.data = 5;

    node* n1 = (node*)malloc(sizeof(node));
    n1->data;


}   