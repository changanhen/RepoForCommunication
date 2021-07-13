#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> PAIR;

int main() {
    priority_queue<PAIR, vector<PAIR>, greater<PAIR> > q, q_ans;
    LL n, quality, ctr = 0;
    scanf("%lld", &n);
    for (LL i = 0; i < n; i++)
    {
        scanf("%lld", &quality);
        q.push(make_pair(quality, i));
    }
    while (!q.empty())
    {
        PAIR p1 = q.top();
        q.pop();
        //最后一次特判
        if (q.empty())
        {
            LL tmp = p1.first;
            p1.first = p1.second;
            p1.second = tmp;
            q_ans.push(p1);
            break;
        }
        PAIR p2 = q.top();
        //核心步骤
        if (p1.first == p2.first)
        {
            p2.first *= 2;
            q.pop();
            q.push(p2);
        }
        else 
        {
            LL tmp = p1.first;
            p1.first = p1.second;
            p1.second = tmp;
            q_ans.push(p1);
        }
    }
    LL sz = q_ans.size();
    //答案第一行
    printf("%lld\n", sz);
    //答案第二行
    while (!q_ans.empty())
    {
        PAIR qq = q_ans.top();
        q_ans.pop();
        ctr == 0 ? printf("%lld", qq.second): printf(" %lld", qq.second);
        ctr++;
    }
}