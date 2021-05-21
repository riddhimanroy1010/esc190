#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void read_in_terms(struct term **terms, int *pnterms, char *filename){

    char line[200];
    FILE *fp = fopen(filename, "r");
    fgets(line, sizeof(line), fp);
    *pnterms = atoi(line);
    printf("%d", *pnterms);
    *terms = (struct term *)malloc(sizeof(struct term *)*(*pnterms));
    for(int i = 0; i < *pnterms; i++){
        fgets(line, sizeof(line), fp);
        (*terms + i)->weight = (double)atoi(line);
        //terms[i]->term = 
        printf("%f \n", (*terms + i)->weight);
    }
}