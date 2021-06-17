#include <stdio.h>
int main()
{
    char c;
    int statics[26] = { 0 };
    while ((c = getchar()) != '\n')
    {
        for (int i = 0; i < 26; i++)
        {
            if (c == 'a' + i || c == 'A' + i)
                statics[i]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        i? printf(",%d", statics[i]): printf("%d", statics[i]);
    }
}