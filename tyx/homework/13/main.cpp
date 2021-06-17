#include <stdio.h>
int main()
{
    int get, array[4], tmp, put = 0;
    scanf("%d", &get);
    for (int i = 0; i < 4; i++)
    {
        array[3 - i] = get % 10;
        get = (get - get % 10) / 10;
    }
    for (int i = 0; i < 4; i++)
    {
        array[i] = (array[i] + 5) % 10;
    }
    tmp = array[0];
    array[0] = array[3];
    array[3] = tmp;
    tmp = array[1];
    array[1] = array[2];
    array[2] = tmp;
    put = 1000 * array[0] + 100 * array[1] + 10 * array[2] + array[3];
    printf("%d", put);
}