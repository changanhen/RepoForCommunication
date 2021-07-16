#include <bits/stdc++.h>

using namespace std;

string str[100005];

int main() {
    int n;
    int k;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        //scanf("%s", &str[i]);
        cin >> str[i];
        for (string::iterator p = str[i].begin(); p != str[i].end(); p++)
        {
            if (p == str[i].begin())
                k = 26 - *p + 'a';
            *p = (*p - 'a' + k) % 26 + 'a';
        }
    }
    string ans = str[0];
    for (int i = 1; i < n; i++)
    {
        if (str[i] < ans)
            ans = str[i];
    }
    //printf("%s", ans);
    cout << ans;
}