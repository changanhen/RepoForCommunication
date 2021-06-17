#include <stdio.h>
int main()
{
    int m, n;
    int ack(int m, int n);
    scanf("%d %d", &m, &n);
    printf("ack(%d,%d)=%d", m, n, ack(m, n));
}
int ack(int m, int n)
{
    if (!m)
        return n + 1;
    else if (!n)
        return ack(m - 1, 1);
    else
        return ack(m - 1, ack(m, n - 1));
}