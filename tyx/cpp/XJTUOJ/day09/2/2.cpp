#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int trie[26][1000005];

int main() {
    char str[1005];
    scanf("%s", str);
    int ctr = 0, n = strlen(str), ans = 0, tmp1 = 0;
    for (int i = 0; i < n; i++)
    {
        tmp1 = 0;
        for (int j = i; j < n; j++)
        {
            int& tmp2 = trie[str[j] - 'a'][tmp1];
            if (tmp2 == 0)
            {
                ctr++;
                tmp2 = ctr;
                ans++;
            }
            tmp1 = tmp2;
        }
    }
    printf("%d", ans);
}