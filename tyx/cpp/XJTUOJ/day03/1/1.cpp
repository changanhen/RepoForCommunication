#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> mp;
    mp.clear();
    int n, value1, rank = 0, value2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value1);
        if (value1 != value2)
        {
            rank++;
            mp[value1] = rank;
        }
        else 
            mp[value1] = rank;
        value2 = value1;
    }
    int value;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        arr[i] = mp[value];
    }
    for (int i = 0; i < n; i++)
    {
        i == 0 ? printf("%d", arr[i]) : printf(" %d", arr[i]);
    }
}