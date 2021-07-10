#include <bits/stdc++.h>
#include <malloc.h>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int* arr = (int*)malloc((n + 1) * sizeof(int));
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n + 1);
    int l = 0, r = k, fnl = k;
    k = (l + r) / 2;
    while (k != l)
    {
        int ctr = 0;
        bool ult = 0;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] - arr[flag] >= k)
            {
                ctr++;
                flag = i;
            }
        }
        if (fnl - arr[flag] >= k)
            ctr++;
            //ult = 1;
        if (ctr >= n - m + 1/* && ult*/)
        {
            l = k;
            k = (k + r + 1) / 2;
        }
        else 
        {
            r = k;
            k = (k + l) / 2;
        }
    }
    int ctr = 0;
    bool ult = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] - arr[flag] >= r)
        {
            ctr++;
            flag = i;
        }
    }
    if (fnl - arr[flag] >= r)
        ctr++;
        //ult = 1;
    if (ctr >= n - m + 1 /*&& ult*/)
        printf("%d", r);
    else 
        printf("%d", k);
}