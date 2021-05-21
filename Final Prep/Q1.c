//
// Created by riddh on 4/20/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


char* concat_all(char **strs, int strs_sz){

    char* out = malloc(sizeof(char) * strs_sz);
    strcpy(out, strs[0]);

    for (int i = 1; i < strs_sz; i++)
    {
        strcat(out, *(strs + i));
    }

    return out;
}


