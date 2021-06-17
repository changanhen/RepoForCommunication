#include <stdio.h>
int main()
{
    char str[101] = {' '};
    int k;
    scanf("%s %d", str, &k);
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
    }
    printf("%s", str);
}