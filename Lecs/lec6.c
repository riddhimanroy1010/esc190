#include <stdio.h>
#include <stdlib.h>

/*
append
length
max
rec_length
rec_max
delete
*/

/*
linked lists
    provide a structure where you can append elements and delete and so on that cannot be done to a C array
    C arrays cannot be modified in terms of size after they've been created

How do they work
    Data + pointer to next -> data + pointer to next ...

*/

struct node
{
    int data; // in python: void* data, and the data type
    struct node *next; //NULL if this is the last node
    
};

void append(struct node* head, int value);
int max(struct node* head);
int length(struct node *head);
int rec_max(struct node *head, int cur_max);
int rec_len(struct node *head, int cur_length);
void free_list(struct node *head);
void free_list_rec(struct node* head);
int make_node(struct node **pnode, int value);

int main(void)
{   

    struct node *node0 = (struct node*)malloc(sizeof(struct node));
    struct node *node1 = (struct node*)malloc(sizeof(struct node));

    node0->data = 3;
    node1->data = 5;
    
    node0->next = node1;
    node1->next = NULL;

    
    append(node0, 3);
    printf("hi \n");

    free_list(node0);
    return 0;
}

void append(struct node* head, int value)
{
    struct node* cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    //cur->next is now equal to null; now sitting at the last element of the array

    //making a new node and putting 8, then having current point to this tail
    struct node* tail = (struct node*)malloc(sizeof(struct node));
    tail->data = value;
    tail->next = NULL;

    cur->next = tail;

}   

int max(struct node* head)
{  
    struct node *cur= head;
    int cur_max = cur->data;

    while (cur->next != NULL)
    {
        if (cur->data > cur_max)
        {
            cur_max = cur->data;
        }
        cur = cur->next;
    }
    return cur_max;
}

int length(struct node *head)
{
    int len = 0;
    struct node *cur= head;

    while (cur->next != NULL)
    {
        len++;
        cur = cur->next;
    }

    return len;
}

int rec_max(struct node *head, int cur_max)
{
    if (head == NULL)
    {
        return cur_max;
    }

    if (head->data > cur_max)
    {
        cur_max = head->data;
    }
    head = head->next;
    rec_max(head, cur_max);
}

int rec_len(struct node *head, int cur_length)
{
    if (head == NULL)
    {
        return cur_length;
    }
    else
    {
        cur_length++;
    }
    head = head->next;
    rec_len(head, cur_length);
}

void free_list(struct node *head)
{
    struct node* next = head->next;
    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
}

void free_list_rec(struct node* head)
{
    if (head->next == NULL)
    {
        free(head);
    }
    free_list_rec(head->next);
    free(head);
}

int make_node(struct node **pnode, int value)
{
    *pnode = (struct node*)malloc(sizeof(struct node));
    if (pnode == NULL)
    {
        return 1;
    }
    else
    {
        (*pnode)->data = value;
    }
    return 0;
}



