#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct _territory
{
    long double numerator;
    long double denominator;
    long double value;
} territory;

void Bubble(territory* t, int length);

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
    Bubble(t, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d/%d\n", (int)t[i].numerator, (int)t[i].denominator);
        //cout << t[i].numerator << "/" << t[i].denominator << endl;
    }
}

void Bubble(territory* t, int length){
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (t[j].value < t[j + 1].value)
            {
                territory tmp = t[j];
                t[j] = t[j +1 ];
                t[j + 1] = tmp;
            }
        }
    }
}
