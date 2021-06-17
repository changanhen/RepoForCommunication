#include <stdio.h>
int main()
{
    int Josephus(int n, int m);
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", Josephus(n, m));
}
int Josephus(int n, int m)
{
    return n == 1 ? n : (Josephus(n - 1, m) + m - 1) % n + 1;
}