#include <malloc.h>
#include <iostream>
using namespace std;

void merge_sort(int arr[], int len, int st);

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int* arr = (int*)malloc((n + m) * sizeof(int));
    for (int i = 0; i < n + m; i++)
    {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, n + m, k);
    printf("%d", arr[k - 1]);
}

int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int arr[], int len, int st) {
    int* a = arr;
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < st; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}