#include <stdio.h>
#include <string.h>
int main()
{
    void eliminate(char* string, int begin, int len);
    char string[81] = {' '};
    int begin, end;
    scanf("%[^\n]", string);
    int len = strlen(string);
    for (begin = 0; string[begin] == ' '; begin++);
    for (end = strlen(string) - 1; string[end] == ' '; end--);
    eliminate(string, begin, len);
    for (int i = 0; i < begin; i++)
        printf(" ");
    for (; string[begin] != ' ' && string[begin]; begin++)
        printf("%c", string[begin]);
    end++;
    for (; end < len; end++)
        printf(" ");
}
void eliminate(char* string, int begin, int len)
{
    for (; begin < len; begin++)
    {
        while (string[begin] == ' ')
            for (int i = begin; i <= len; i++)
                string[i] = string[i + 1];
    }
}