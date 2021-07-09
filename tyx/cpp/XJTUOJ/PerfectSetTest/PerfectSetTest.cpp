#include <iostream>
using namespace std;
int main(){
    long long int n, arr[35], sum, ctr, m = 0;
    scanf("%lld", &n);
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    for (long long int k = 0, _max = 1<<n; k < _max; k++)
    {
        sum = 0;
        for (long long int i = 0; i < n; i++)
        {
            if ((k >> i) & 1)
            {
                sum += arr[i];
            }
        }
        if (sum == 0)
            m++;
    }
    printf("%lld", m - 1);
}