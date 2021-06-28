
/*
#include <stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);
    printf("%c%c%c", (ch - 1 + 26 - 'a') % 26 + 'a', ch, (ch + 1 + 26 - 'a') % 26 + 'a');
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char kstr[100];
    int num, k;
    scanf("%d%d", &num, &k);
    itoa(num, kstr, k);
    _strupr(kstr);
    printf("%s", kstr);
}
int Josephus(int n, int m)
{
    return n == 1 ? n : (Josephus(n - 1, m) + m - 1) % n + 1;
}
*/