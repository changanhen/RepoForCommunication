#include <bits/stdc++.h>
#define e 825

using namespace std;

bool isPrime(int n, int prime[], int prime_square[]);

int main()
{
    int prime[e] = {2, 3, 5};         //质数数列
    int prime_square[e] = {4, 9, 25}; //质数的平方，减少重复运算
    int i = 3, k, m = 1;               //几个计数变量
    int n;                            //遍历奇数
    for (n = 7; i < e; n += 2)         //遍历所有数直到第e个质数
    {
        for (k = 1; prime_square[k] <= n; k++) //将n除以所有质数
        {
            m = 1;            //bool计数变量
            if (n % prime[k]) //判断是否为质数
                continue;
            else
            {
                m = 0;
                break;
            }
        }
        if (m == 1)
        {
            prime[i] = n; //录入质数数组
            prime_square[i] = n * n;
            i++;
        }
    }
    int x;
    int ans = 0;
    set<int> s;
    s.clear();
    scanf("%d", &x);
    int arr[21];
    for (int ii = 0; ii < x; ii++)
    {
        scanf("%d", arr + ii);
    }
    for (int mask = 0, tot = 1 << x; mask < tot; mask++)
    {
        int sum = 0;
        for (int jj = 0; jj < x; jj++)
        {
            if ((mask >> jj) & 1)
                sum += arr[jj];
        }
        if (isPrime(sum, prime, prime_square))
        {
            s.insert(sum);
            ans++;
        }
    }
    printf("%d\n%d", ans, s.size());
}

bool isPrime(int n, int prime[], int prime_square[]) {
    bool m = 1;
    if (n == 1 || n == 0)
        return false;
    for (int i = 0; prime_square[i] <= n; i++)
    {
        if (n % prime[i])
            continue;
        else 
        {
            m = 0;
            break;
        }
    }
    return m;
}