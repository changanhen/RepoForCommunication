#include <stdio.h>
#include <string.h>
int main()
{
    char string[201] = { 0 };
    scanf("%s", string);
    for (int i = 1; i < strlen(string) - 2; i++)
    {
        for (int j = 1; j < strlen(string) - 1 - i; j++)
        {
            if (string[j] < string[j + 1])
            {
                char tmp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = tmp;
            }
        }
    }
    printf("%s", string);
}