#include <iostream>
#include <algorithm>
#include <malloc.h>
using namespace std;

//void selection_sort(int a[], int len, int k);

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int* arr = (int*)malloc((n + m) * sizeof(int));
    //int* arr2 = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n + m; i++)
    {
        scanf("%d", &arr[i]);
    }
    //selection_sort(arr, n + m, k);
    sort(arr, arr + n + m);
    printf("%d", arr[k - 1]);
}

/*void selection_sort(int a[], int len, int k) 
{
    int i,j,temp;
 
    for (i = 0 ; i < k ; i++) 
    {
        int min = i;                  // 记录最小值，第一个元素默认最小
        for (j = i + 1; j < len; j++)     // 访问未排序的元素
        {
            if (a[j] < a[min])    // 找到目前最小值
            {
                min = j;    // 记录最小值
            }
        }
        if(min != i)
        {
            temp=a[min];  // 交换两个变量
            a[min]=a[i];
            a[i]=temp;
        }
        /* swap(&a[min], &a[i]);  /   // 使用自定义函数交換
    }
}*/
