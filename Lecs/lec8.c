#include <stdio.h>
#include <stdlib.h>
#include "lec8.h"


#define COURSE 180 //replace any instance of course with 180

//macros
#define ABS(x) if(x  < 0) - x else x;

// Multifile functions

int main(void)
{
    int res = f();
    printf("%d", res);
    return 0;
}\

int max(int a, int b)
{
    return (a > b) ? a : b;
}

#define MAX(x, y) ((x) > (y)) ? (x) : (y)

/*
COND? OUT1 : OUT1

same as
if(COND)
{
    OUT1;
}
else
{
    OUT2;
}