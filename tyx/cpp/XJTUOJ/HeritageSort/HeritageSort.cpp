#include <iostream>
#include <malloc.h>
#include <algorithm>

using namespace std;

typedef struct _territory
{
    long double numerator;
    long double denominator;
    long double value;
} territory;

bool cmp(territory p1, territory p2);

int main(){
    int n;
    scanf("%d", &n);
    territory* t = (territory*)malloc(n * sizeof(territory));
    for (int i = 0; i < n; i++)
    {
        scanf("%llf%llf", &t[i].numerator, &t[i].denominator);
        t[i].value = t[i].numerator / t[i].denominator;
    }
    sort(t, t + n, cmp);
    for (int i = 0; i < n; i++)
    {
        printf("%d/%d\n", (int)t[i].numerator, (int)t[i].denominator);
        //cout << t[i].numerator << "/" << t[i].denominator << endl;
    }
}

bool cmp(territory p1, territory p2)
{
    return p1.value > p2.value;
}