#include <malloc.h>
#include <iostream>
#include <algorithm>

using namespace std;

void merge_sort(int arr[], int len, int st);

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int* arr1 = (int*)malloc(n * sizeof(int));
    int* arr2 = (int*)malloc(m * sizeof(int));
    int* arrk = (int*)malloc(2 * k * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    merge_sort(arr, n + m, k);
    printf("%d", arr[k - 1]);
}

int kmin(int arr[], int arrk[], int len, int k)
{
    for (int i = 0; i < len; i++)
    {
        
    }
    
}