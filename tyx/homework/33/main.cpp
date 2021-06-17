#include <stdio.h>
int main()
{
    char str[101] = {' '}, tmp_ctr = 1, ctr = 1, tmp_char_lct = 0;
    scanf("%s", str);
    for (int i = 0; str[i]; i++)
    {
        for (int j = i + 1; str[i] == str[j]; j++)
        {
            tmp_ctr++;
        }
        if (tmp_ctr > ctr)
        {
            ctr = tmp_ctr;
            tmp_char_lct = i;
        }
        tmp_ctr = 1;
    }
    printf("%c %d %d", str[tmp_char_lct], ctr, tmp_char_lct);
}