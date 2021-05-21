#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "autocomplete.h"

int main(void)
{
    struct term* terms;
    int nterms;
    read_in_terms(&terms, &nterms, "text.txt");
    int l = lowest_match(terms, nterms, "Tor");
    int h = highest_match(terms, nterms, "Tor");
    printf("l = %d, h = %d\n", l, h);
    struct term* answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    //free allocated blocks here -- not required for the project, but good practice
    if (n_answer > 0)
    {
        for (int i = 0; i < n_answer; i++)
        {
            printf("%f - %s\n", (answer + i)->weight, (answer + i)->term);
        }
        printf("---------\n");
        printf("%f - %s\n", (answer)->weight, (answer)->term);
    }
    return 0;
}