#include <stdio.h>
#include<string.h>
int main()
{
    char str[100]; //input string with size 100

    int words = 0, newline = 0, characters = 0,i,j,len;
    scanf("%[^~]", &str);

    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[0] == ' ')
        {
            for (i = 0; i < (len - 1); i++)
                str[i] = str[i + 1];
            str[i] = '\0';
            len--;
            i = -1;
            continue;
        }
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (j = i; j < (len - 1); j++)
            {
                str[j] = str[j + 1];
            }
            str[j] = '\0';
            len--;
            i--;
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            words++;
        }
        else if (str[i] == '\n')
        {
            newline++;
            words++;
        }
        else if (str[i] != ' ' && str[i] != '\n')
        {
            characters++;
        }
    }
    if (characters > 0)
    {
        words++;
        newline++;
    }
    printf("Total number of words : %d\n", words);
    printf("Total number of lines : %d\n", newline);
    printf("Total number of characters : %d\n", characters);
    return 0;
}