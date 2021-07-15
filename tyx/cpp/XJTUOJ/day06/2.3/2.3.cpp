#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PAIR;

int main() {
    int n;
    long long int sum = 0;
    scanf("%d", &n);
    stack<PAIR> s;
    s.push(make_pair(0, -1));
    for (int i = 0; i < n; i++)
    {
        int tmp, flag;
        scanf("%d", &tmp);
        PAIR tmpp = s.top();
        flag = tmpp.second;
        PAIR tmppp = make_pair(tmp, i);
        while (tmppp.first > tmpp.first)
        {
            s.pop();
            if (s.empty())
            {
                flag = -1;
                break;
            }
            tmpp = s.top();
            flag = tmpp.second;
        }
        s.push(tmppp);
        sum += (tmppp.second - flag - 1);
    }
    printf("%lld", sum);
}