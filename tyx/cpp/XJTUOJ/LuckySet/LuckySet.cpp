#include <iostream>
using namespace std;
int main(){
    int n, arr[20], sum, ctr, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int k = 1, _max = 1<<n; k < _max; k++)
    {
        sum = 0;
        ctr = 0;
        for (int i = 0; i < n; i++)
        {
            if ((k >> i) & 1)
            {
                sum += arr[i];
                ctr++;
            }
        }
        if (sum == 0 && (ctr & 1) == 0)
            m++;
    }
    printf("%d", m);
}