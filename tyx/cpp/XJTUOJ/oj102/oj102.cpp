#include <bits/stdc++.h>

using namespace std;

int main() {
    char str[1005];
    scanf("%s", str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 26;
    int S = strlen(str);
    printf("%d\n%s", S, str);
}