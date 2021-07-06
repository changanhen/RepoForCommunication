#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct _territory
{
    long double numerator;
    long double denominator;
    long double value;
} territory;

void quick_sort(territory* t, int len);
void swap(territory *x, territory *y);

int main(){
    int n;
    cin >> n;
    territory* t = (territory*)malloc(n * sizeof(territory));
    for (int i = 0; i < n; i++)
    {
        //scanf("%ld%ld", t[i].numerator, t[i].denominator);
        cin >> t[i].numerator >> t[i].denominator;
        t[i].value = t[i].numerator / t[i].denominator;
    }
    /*if (n == 2)
    {
        if (t[0].value < t[1].value)
            swap(&t[0], &t[1]);
    }
    else*/
        quick_sort(t, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d/%d\n", (int)t[i].numerator, (int)t[i].denominator);
        //cout << t[i].numerator << "/" << t[i].denominator << endl;
    }
}

void swap(territory *x, territory *y) {
    territory t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(territory* t, int start, int end) {
    if (start >= end)
        return;
    long double mid = t[end].value;
    int left = start, right = end - 1;
    while (left < right) {
        while (t[left].value >= mid && left < right)
            left++;
        while (t[right].value < mid && left < right)
            right--;
        swap(&t[left], &t[right]);
    }
    if (t[left].value < t[end].value)
        swap(&t[left], &t[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(t, start, left - 1);
    quick_sort_recursive(t, left + 1, end);
}
void quick_sort(territory* t, int len) {
    quick_sort_recursive(t, 0, len - 1);
}