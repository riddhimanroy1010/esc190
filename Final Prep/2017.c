//
// Created by riddh on 4/18/2021.
//
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct BSTnode{
    int data;
    struct BSTnode* lchild;
    struct BSTnode* rchild;
};

float averageLinkedList(struct Node * L, int * average)
{
    if (L->next == NULL)
    {
        return (float)*average;
    }
    else
    {
        *average += L->data;
        int n = 0;
    }
}

int sumBST(struct BSTnode* root)
{
    int sum = 0;
    if (root->lchild != NULL && root->lchild->data > 10)
    {
        sum += root->lchild->data;
    }
    else if (root->rchild != NULL && root->lchild->data > 10)
    {
        sum += root->rchild->data;
    }
    else
    {
        return 0;
    }
    sum += sumBST(root->lchild);
    sum += sumBST(root->rchild);

    return sum;
}

struct BSTnode* insertBST(struct BSTnode* root, int value)
{
    if (!root)
    {
        root = (struct BSTnode*)malloc(sizeof(struct BSTnode));
        root->data = value;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root = root->lchild;
        return insertBST(root, value);
    }
    else if (value >= root->data)
    {
        root = root->rchild;
        return insertBST(root, value);
    }
}

struct searchNode{
    int vLabel;
    struct searchNode* lchild;
    struct searchNode* rchild;
};

void inOrderTraversal(struct searchNode* root)
{
    if (root != NULL)
    {
        printf("%d", root->vLabel);
    }
    struct searchNode* holding = (struct searchNode*)malloc(sizeof(struct searchNode));
    holding = root->rchild;
    while (root != NULL)
    {
        printf("%d", root->vLabel);
        if (root->lchild != NULL && root->rchild != NULL)
        {
            root = root->lchild;
        }
        if (root->lchild == NULL)
        {
            root = holding;
        }
    }
}

#define NODES 6
struct adjMat
{
    int mat[NODES][NODES];
    int visitedNodes[NODES];

};

struct Queue{
    int value;
    struct Queue* next;

};

struct Queue* initqueue()
{
    struct Queue* init = (struct Queue*)malloc(sizeof(struct Queue));
    init->next = NULL;
    return init;
}
void enqueue(struct Queue* q, int node)
{
    struct Queue* cur = (struct Queue*)malloc(sizeof(struct Queue));
    cur->value = node;
    cur->next = q;

}
int dequeue(struct Queue* q)
{
    struct Queue* cur = (struct Queue*)malloc(sizeof(struct Queue));
    *cur = *q;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur->value;

}
int isEmpty(struct Queue* q)
{
    if (q == NULL)
    {
        return 1;
    }
    return 0;
}

void bfTraversal(struct adjmat* aM, int n)
{
    struct Queue* queue = initqueue();
    enqueue(queue, 0);
    while (isEmpty(aM) == 0)
    {
        int cur = dequeue(queue);
        for (int i = 0; i < 6; i++)
        {
            if (aM->mat[cur][i] == 1)
            {
                enqueue(queue, aM->mat[cur][i])
                printf("%d", aM->mat[cur][i]);
            }
        }
    }
}

struct Node* mergeLinkedLists(struct Node* L1, struct Node* L2)
{
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));
    *cur = *L1;

    while (L1->next != NULL && L2->next != NULL)
    {
        *(cur) = *(L2)->next;
        L2 = L2->next;
        cur = cur->next;
        *(cur) = *(L1)->next;
        L1 = L1->next;
        cur = cur->next;
    }
    if (L1->next != NULL && L2->next == NULL)
    {
        *(cur)->next = *(L1)->next;
    }
    else if (L2->next != NULL && L1->next == NULL)
    {
        *(cur)->next = *(L2)->next;
    }

    return cur;
}

void bubbleSort(struct Node** l1)
{
    int len = 0;
    int counter = 0;
    int iter = 0;

    while ((*l1)->next != NULL)
    {
        len++;
    }
    struct Node* cur = (struct Node*)malloc(sizeof(struct Node));

    while (iter < len)
    {
        cur = *l1;
        while (counter < len - iter)
        {
            if ((cur)->data > (cur)->next->data)
            {
                struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
                *temp = *cur;
                cur = cur->next;
                cur->next = temp;
                counter++;
            }
            if (counter == len - iter)
            {
                iter++;
            }
            else if (cur->next != NULL)
            {
                cur = cur->next;
            }

        }
    }

}