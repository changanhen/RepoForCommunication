#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l, r;
    scanf("%d", &n);
    int upr = (int)sqrt(10000005);
    bool *array = (bool *)malloc(10000005);
    //memset(array, true, sizeof(array));
    for (int i = 0; i < 10000005; i++)
    {
        array[i] = true;
    }
    array[1] = true;
    array[0] = false;
    for (int i = 4; i < 10000005; i += 2)
    {
        array[i] = false;
    }
    for (int i = 3; i <= upr; i++)
    {
        if (array[i] == false)
            continue;
        for (int j = i * i; j < 10000005; j += 2 * i)
        {
            if (array[i])
            {
                array[j] = false;
            }
        }
    }
    int output[51] = { 0 }, ptr = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l, &r);
        int ctr = 0;
        for (int j = l; j <= r; j++)
        {
            if (array[j])
                ctr++;
        }
        output[ptr++] = ctr;
    }
    for (int i = 0; i < ptr; i++)
    {
        printf("%d\n", output[i]);
    }
}