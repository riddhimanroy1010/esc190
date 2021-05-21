#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_str_len(char* s1);
void my_strcpy(char* dest, char* src);
void my_strcpy2(char* dest, char* src);

int main(void)
{
    char c1 = 'a';
    char c2 = 'A';

    char* s2 = (char *)malloc(sizeof(char) * 20);
    s2[0] = "A";
    char s3[20];

    char s4[4] = "ab";
    printf("%s", s4);
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%c %i \n", s4[i], i);
    }  

    //copying strings
    char s5[20] = "abc";
    char s6[20];
    strcpy(s6, s5); //s6 is detination, s5 is origin
    int b = strlen(s5); //find length of strings
    printf("len of s5 is %d", b);
    if (strcmp(s5, s6) == 0) //compares strings, if same return 0
    {
        printf("yay");
    }
    return 0;
}

int my_str_len(char* s1)
{
    int len = 0;
    while (s1 != NULL)
    {
        len++;
        s1++;
    }
    return len;
}

void my_strcpy(char* dest, char* src)
{   
    while (src != NULL)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src;
}

void my_strcpy2(char* dest, char* src)
{   
    while (src != NULL)
    {
        *dest++ = *src++;
    }
}

