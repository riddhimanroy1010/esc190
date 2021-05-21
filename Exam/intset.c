//
// Created by riddh on 3/11/2021.
//

#include "intset.h"
#include <stdlib.h>
#include <stdio.h>

//Create an intset, and place a pointer to it in *s.
void intset_create(struct intset **s)
{
    *s = (struct intset*)malloc(sizeof(struct intset));
    (*s)->head = NULL;
}

//Add the elements from attay elems to intset s. There are
//num_elems elements in elems
void intset_add(struct intset *s, int *elems, int num_elems)
{
    for (int i = 0; i < num_elems; i++)
    {
        if (s->head == NULL)
        {
            struct node* firsthead = (struct node*)malloc(sizeof(struct node));
            firsthead->data = elems[i];
            s->head = firsthead;
            s->head->next = NULL;
        }
        else if (intset_iselem(s, elems[i]) == 1)
        {
            i++;
        }
        else
        {
            struct node* cur = s->head;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            //cur->next is now equal to null; now sitting at the last element of the array

            //making a new node and putting 8, then having current point to this tail
            struct node* tail = (struct node*)malloc(sizeof(struct node));
            tail->data = elems[i];
            tail->next = NULL;

            cur->next = tail;
        }

    }
}

//Return 1 if element elem is in intset s. Otherwise return 0.
int intset_iselem(struct intset *s, int elem)
{
    struct node* cur = s->head;
    if (cur->next == NULL)
    {
        return 0;
    }
    while (cur->next->next != NULL)
    {
        if (cur->data == elem)
        {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

//Remove element elem from s, of eleme is in s. If the element
//is not in s, do nothing.
//free memory that's not needed anymore
void intset_remove(struct intset *s, int elem)
{
    if (intset_iselem(s, elem) == 1)
    {
        struct node* cur = s->head;
        while(cur->next->data != elem)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        free(cur->next);
    }
    else
    {
        return;
    }
}

void intset_union(struct intset *s1, struct intset *s2, struct intset **s3)
{
    intset_create(s3);
    struct node* cur = s1->head;
    while(cur->next != NULL)
    {
        intset_add(*s3, &(cur->data), 1);
    }

    struct node* cur2 = s2->head;
    while(cur2->next != NULL)
    {
        intset_add(*s3, &(cur->data), 1);
    }
}




