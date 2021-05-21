//
// Created by riddh on 3/11/2021.
//

int my_strncmp(char *str1, char *str2, int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        if ((*str1 != '\0') && (*str2 != '\0'))
        {
            if (*str1 != *str2)
            {
                return (int)(*str1) - (int)(*str2);
            }
            else if (*str1 == *str2)
            {
                *str1++; *str2++;
                my_strncmp(str1, str2, num - 1);
            }
            else
            {
                return 0;
            }
        }
        else if ((*str1 != '\0') && (*str2 == '\0'))
        {
            return (int)(*str1);
        }
        else if ((*str1 == '\0') && (*str2 != '\0'))
        {
            return -(int)(*str2);
        }
    }

}
