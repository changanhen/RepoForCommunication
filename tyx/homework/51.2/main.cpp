#include <stdio.h>
#include <string.h>
int main()
{
    void eliminate(char* string, int begin, int end);
    char string[81] = {' '};
    int begin, end;
    scanf("%[^\n]", string);
    for (begin = 0; string[begin] == ' '; begin++);
    for (end = strlen(string) - 1; string[end] == ' '; end--);
    eliminate(string, begin, end);
    for (int i = 0; i < begin; i++)
        printf(" ");
    for (; string[begin] != ' ' && string[begin]; begin++)
        printf("%c", string[begin]);
}
void eliminate(char* string, int begin, int end)
{
    for (; begin <= end; begin++)
    {
        while (string[begin] == ' ')
            for (int i = begin; i <= end; i++)
                string[i] = string[i + 1];
    }
}