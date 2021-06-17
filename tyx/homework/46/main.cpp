#include <stdio.h>
#include <stdlib.h>
int main()
{
    int* a, * b, a_num, b_num, ctr = 0;
    scanf("%d", &a_num);
    a = (int*)malloc(4 * a_num);
    for (int i = 0; i < a_num; i++)
    {
        scanf("%d", a + i);
    }
    scanf("%d", &b_num);
    b = (int*)malloc(4 * b_num);
    for (int i = 0; i < b_num; i++)
    {
        scanf("%d", b + i);
    }
    for (int i = 0; i < a_num; i++)
    {
        for (int j = 0; j < b_num; j++)
        {
            if (*(a + i) == *(b + j))
            {
                ctr? printf(" %d", *(b + j)): printf("%d", *(b + j));
                ctr++;
                break;
            }
        }
    }
    free(a);
    free(b);
}