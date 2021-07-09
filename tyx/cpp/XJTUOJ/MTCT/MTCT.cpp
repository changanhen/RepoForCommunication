#include <iostream>
#include <malloc.h>
using namespace std;
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(m * sizeof(int));
    int ctr1 = 0, ctr2 = 0, get1 = 0, get2 = 0, tmp = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    get1 = arr1[ctr1++];
    get2 = arr2[ctr2++];
    tmp = get1 < get2 ? get1 : get2;
    int i = 0;
    bool ion;
    /*for (; i < k - 2; i++)
    {
        if ((tmp < get2 && ctr1 != n) || (ctr2 == m && ctr1 != n))
        {
            get1 = arr1[ctr1++];
            tmp = get1 < get2 ? get1 : get2;
        }
        if ((tmp < get1 && ctr2 != m) || (ctr1 == n && ctr2 != m))
        {
            get2 = arr2[ctr2++];
            tmp = get1 < get2 ? get1 : get2;
        }
        if (get1 == get2 && ctr1 != n)
        {
            get1 = arr1[ctr1++];
            tmp = get1 < get2 ? get1 : get2;
        }
        if (get1 == get2 && ctr1 != m)
        {
            get2 = arr2[ctr2++];
            tmp = get1 < get2 ? get1 : get2;
        }
    }*/
    for (; i < k - 1; i++)
    {
        if (tmp < get2)
        {
            get1 = arr1[ctr1++];
            tmp = get1 < get2 ? get1 : get2;
        }
        else if (tmp < get1)
        {
            get2 = arr2[ctr2++];
            tmp = get1 < get2 ? get1 : get2;
        }
        else if (get1 == get2)
        {
            get1 = arr1[ctr1++];
            tmp = get1 < get2 ? get1 : get2;
        }
        if (ctr1 == n)
        {
            ion = 1;
            i++;
            break;
        }
        if (ctr2 == m)
        {
            ion = 0;
            i++;
            break;
        }
    }
    if (ion)
        for (; i < k - 2; i++)
            tmp = arr2[ctr2++];
    else
        for (; i < k - 2; i++)
            tmp = arr1[ctr1++];
    printf("%d", tmp);
}