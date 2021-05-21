//
// Created by riddh on 4/19/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
struct node{
    int height;
    int data;
    struct node* lchild;
    struct node* rchild;
};

struct node* rightrotate(struct node* n);
struct node* leftrotate(struct node* n);
int height(struct node* n);
int max(int i, int j);

struct node* balanceBST(struct node* n)
{
    return n;
    //PASS
}

int lenfinder(char* str)
{
    int len = 0;
    while (*str)
    {
        *str++;
        len++;
    }
    return len;
}

char* join(int n, char* strs[], char* sep)
{
    int len_strs = 0;
    for (int i = 0; i < n; i++)
    {
        len_strs+= lenfinder(strs[i]);
    }
    int len_sep = lenfinder(sep);

    char* out = (char*)malloc(sizeof(char) * (len_strs + len_sep));

    int i = 0;
    while (i < len_strs + len_sep)
    {
        out[i] = *strs[i];
        out[i+1] = *sep;
        i+=2;
    }
}

typedef struct list_node{
    long value;
    struct list_node *prev;
    struct list_node *next;
} list_node_t;

bool find(long elem, list_node_t **first)
{
    list_node_t* cur = (list_node_t*)malloc(sizeof(list_node_t));
    *cur = **first;

    while (cur->next != NULL)
    {
        if (cur->value == elem)
        {
            list_node_t* head = (list_node_t*)malloc(sizeof(list_node_t));
            head->value = elem;
            head->next = *first;
            head->prev = NULL;
            cur = cur->prev;
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    free(cur);
}

typedef struct bst_node{
    long value;
    struct bst_node *left;
    struct bst_node *right;
} bst_node_t;

long bst_max(const bst_node_t *root)
{
    long cur_max = 0;

    bst_node_t* cur = (bst_node_t*)malloc(sizeof(bst_node_t));
    *cur = *root;

    while (cur->right != NULL)
    {
        cur = cur->right;
    }

    return cur->value;

}

bst_node_t* clone(const bst_node_t* root)
{
    bst_node_t* copy = (bst_node_t*)malloc(sizeof(bst_node_t));
    copy->value = root->value;

    if (root->right != NULL)
    {
        copy->right = copy(root->right);
    }
    else
    {
        copy->right = NULL;
    }
    if (root->left != NULL)
    {
        copy->left = clone(root->left);
    }
    else
    {
        copy->left = NULL;
    }
    return copy;
}

unsigned int hash10(unsigned int num)
{
    unsigned sum = 0;
    if (num < 10)
    {
        return num;
    }

    while (num >= 10)
    {
        sum += num % 10;
        num = num/10;
    }
    sum += num;
    if (sum >= 10)
    {
        return hash10(sum);
    }
    else
    {
        return sum;
    }
}








