#include <bits/stdc++.h>

using namespace std;

string str[100005];
string ans[100005];

int main() {
    int n;
    int k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &str[i]);
        for (auto p : str[i])
        {
            if (p == *str[i].begin())
                k = 26 - p + 'a';
            p = (p - 'a' + k) % 26 + 'a';
        }
    }
    string ans;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] < str[i + 1])
            ans = str[i];
        else
            ans = str[i + 1];
    }
    printf("%s", ans);
}