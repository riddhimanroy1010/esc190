//
// Created by riddh on 3/11/2021.
//

#include <stdio.h>
#include <stdlib.h>

int lenfinder(char* str)
{
    int len = 0;
    while (*(str + len))
    {
        len++;
    }
    return len;
}

int dotfinder(char* str)
{
    int counter = 0;
    while (*(str + counter) != '.')
    {
        counter++;
    }
    return counter;

}

int positive_multiplier(int n)
{
    int res = 1;
    for(int i = 0; i < n; i++)
    {
        res = res * 10;
    }
    return res;

}

double negative_multiplier(int n)
{
    double res = 1.0;
    for(int i = 0; i < n; i++)
    {
        res = res / 10;
    }
    return res;

}

double my_atof(char *str)
{
    int len = lenfinder(str) - 1;
    int dot_index = dotfinder((str));

    int whole_indices = dot_index;

    double out = 0;
    for(int i = 0; i < whole_indices; i++)
    {
        out += (*str -'0') * positive_multiplier((whole_indices - i - 1));
        str++;
    }
    str++;
    for(int i = 0; i < dot_index; i++)
    {
        if (*(str))
        {
            out += (*str -'0') * negative_multiplier((i + 1));
            str++;
        }

    }

    return out;

}
