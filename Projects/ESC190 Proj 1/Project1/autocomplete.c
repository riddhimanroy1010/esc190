#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "autocomplete.h"

int lexisort(const void* a, const void* b)
{
    return(strcmp(((struct term*)a)->term, ((struct term*)b)->term));
}

int weightsort(const void* a, const void* b)
{
    double res = (-((struct term*)a)->weight + ((struct term*)b)->weight);
    if (res < 0)
    {
        return -1;
    }
    else if (res > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lenfinder(char* str)
{
    int len = 0;
    while (isalpha(str[len]) != 0)
    {
        len++;
    }
    return len;
}

void read_in_terms(struct term** terms, int* pnterms, char* filename)
{
    char line[200];
    FILE* fp = fopen(filename, "r");
    fgets(line, sizeof(line), fp);
    *pnterms = atoi(line);
    *terms = (struct term*)malloc(sizeof(struct term) * (*pnterms));
    for (int i = 0; i < *pnterms; i++)
    {
        fgets(line, sizeof(line), fp);
        int j = 0;
        strcpy((*terms + i)->term, line);
        while ((isspace((*terms + i)->term[j])) != 0)
        {
            j++;
        }
        int weight_strt = j;
        while ((isspace((*terms + i)->term[j])) == 0)
        {
            j++;
        }
        int weight_end = j - 1;
        int term_strt = j + 1;

        int term_end = strlen((*terms + i)->term) - 2;

        char weight[200];
        strncpy(weight, (*terms + i)->term + weight_strt, weight_end);
        (*terms + i)->weight = (double)atol(weight);

        char term[200];
        strncpy(term, (*terms + i)->term + term_strt, term_end);
        strcpy((*terms + i)->term, term);
        int len = strlen((*terms + i)->term);
        if ((*terms + i)->term[len - 1] == '\n')
        {
            (*terms + i)->term[len - 1] = '\0';
        }

    }
    qsort(*terms, *pnterms, sizeof(struct term), lexisort);
    fclose(fp);
}

int lowest_match(struct term* terms, int nterms, char* substr)
{
    int lower = 0;
    int upper = nterms;
    int len = lenfinder(substr);
    while (lower < upper)
    {
        int mid = (lower + upper) / 2;
        if (strncmp(substr, (terms + mid)->term, len) != 0 && strcmp((terms + mid)->term, substr) < 0)
        {
            lower = mid + 1;
        }
        else if (strncmp(substr, (terms + mid)->term, len) != 0 && strcmp((terms + mid)->term, substr) > 0)
        {
            upper = mid;
        }
        else if (mid > 0 && strncmp(substr, (terms + mid)->term, len) == 0)
        {
            upper = mid;
        }
        else
        {
            return mid;
        }
    }
    if (lower == upper)
    {
        return lower;
    }
    return -2147483647;
}


int highest_match(struct term* terms, int nterms, char* substr)
{
    int lower = 0;
    int upper = nterms;
    int cursor = -2147483647;
    int len = lenfinder(substr);
    while (lower <= upper)
    {
        int mid = (lower + upper) / 2;
        if (strncmp(substr, (terms + mid)->term, len) != 0 && strcmp(substr, (terms + mid)->term) > 0)
        {
            lower = mid + 1;
        }
        else if (strncmp(substr, (terms + mid)->term, len) != 0 && strcmp(substr, (terms + mid)->term) < 0)
        {
            upper = mid - 1;
        }
        else if (strncmp(substr, (terms + mid)->term, len) == 0)
        {
            if (mid > cursor || cursor < 0)
            {
                cursor = mid;
            }
            lower = mid + 1;
        }

    }
    return cursor;
}

void autocomplete(struct term** answer, int* n_answer, struct term* terms, int nterms, char* substr)
{
    int higher_match = highest_match(terms, nterms, substr);
    int lower_match = lowest_match(terms, nterms, substr);

    if (higher_match < 0 || lower_match < 0)
    {
        *n_answer = 0;
        return;
    }

    *n_answer = (higher_match - lower_match) + 1;
    *answer = (struct term*)malloc(sizeof(struct term) * (*n_answer));

    int counter = 0;

    for (int i = lower_match; i < lower_match + *n_answer; i++)
    {
        strcpy((*answer + counter)->term, (terms + i)->term);
        (*answer + counter)->weight = (terms + i)->weight;
        counter++;
    }
    qsort(*answer, *n_answer, sizeof(struct term), weightsort);
}


