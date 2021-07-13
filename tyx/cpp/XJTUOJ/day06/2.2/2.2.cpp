#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int LL;

int main() {
    LL n;
    scanf("%llu", &n);
    LL* arr = (LL*)malloc(n * sizeof(LL));
    for (LL i = 0; i < n; i++)
    {
        scanf("%llu", arr + i);
    }
    LL sum = 0;
    for (LL i = n - 1; i > 0; i--)
    {
        LL j = i - 1;
        for (; arr[j] < arr[i]; j--)
        {
            if (j == 0)
            {
                sum += i - j;
                break;
            }
        }
        if (j != 0)
            sum += i - j - 1;
    }
    printf("%llu", sum);
}