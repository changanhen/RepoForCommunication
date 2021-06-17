#include <stdio.h>
#include <string.h>
typedef struct letter
{
    char ltr;
    int ctr;
} chs;
int main()
{
    void ch_bubble(chs characters[]);
    char string[82];
    scanf("%[^\n]", string);
    chs characters[26];
    for (int i = 0; i < 26; i++)
    {
        characters[i].ctr = 0;
        characters[i].ltr = i + 'A';
    }
    for (int i = 0; i < strlen(string); i++)
    {
        /*if (string[i] - 'a' >= 0 && string[i] - 'a' < 26)
            characters[string[i] - 'a'].ctr++;
        if (string[i] - 'A' >= 0 && string[i] - 'A' < 26)
            characters[string[i] - 'A'].ctr++;*/
        for (int j = 0; j < 26; j++)
        {
            if (string[i] == 'a' + j || string[i] == 'A' + j)
                characters[j].ctr++;
        }
    }
    ch_bubble(characters);
    for (int i = 0; i < 26; i++)
    {
        i ? printf(" %c-%d", characters[i].ltr, characters[i].ctr) : printf("%c-%d", characters[i].ltr, characters[i].ctr);
    }
}
void ch_bubble(chs chracters[])
{
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25 - i; j++)
        {
            if (chracters[j].ctr < chracters[j + 1].ctr)
            {
                chs tmp = chracters[j];
                chracters[j] = chracters[j + 1];
                chracters[j + 1] = tmp;
            }
        }
    }
}