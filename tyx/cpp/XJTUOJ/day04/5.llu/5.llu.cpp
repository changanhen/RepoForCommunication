#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int LL;
/**
 * @brief long long int PAIR
 * @param <下一位上的数，当前数值>
 */
typedef pair<LL, LL> PAIR;

int main() {
    LL n, m, ctr = 0, flag = 0, flag_ft = 0, layer = 0, layer_counter = 0;
    LL _min = 18446744073709551615;
    bool _out = false;
    scanf("%llu%llu", &n, &m);
    while (m % 10 == 0)
    {
        m /= 10; //把0归入非0情况
        ctr++;
    }
    queue<PAIR> q;
    /**
     * @brief 对个位分类讨论以剪枝
     */
    LL tmp = m % 10;
    if (tmp == 1 || tmp == 3 || tmp == 7 || tmp == 9)
    {
        q.push(make_pair(0, 0));
        layer++;
        for (LL i = 1; i < n; i++)
        {
            q.push(make_pair(i, 0));
            flag_ft = i;
            layer++;
        }
    }
    if (tmp == 2 || tmp == 4 || tmp == 6 || tmp == 8)
    {
        for (LL i = 0; i < n; i += 2)
        {
            q.push(make_pair(i, 0));
            flag_ft = i;
            layer++;
        }
    }
    if (tmp == 5)
    {
        q.push(make_pair(0, 0));
        flag_ft = 0;
        layer++;
        if (n > 5)
        {
            q.push(make_pair(5, 0));
            flag_ft = 5;
            layer++;
        }
    }
    /**
     * @brief bfs扫描最小正确答案
     */
    while (!q.empty())
    {
        PAIR P = q.front();
        LL tmp = P.first * (LL)pow(10, flag) + P.second;
        if (P.first == flag_ft)
        {
            flag++; //flag表示10的flag次方，用一个if来检测bfs到第几位了
            //layer *= n;
            flag_ft = -1;
        }
        else if (P.first == n - 1)
            layer_counter++;
        if (layer_counter == layer)
        {
            layer *= n; //layer表示该层要进行多少次0-9的push，检测到最后一次即跳出
            layer_counter = 0;
            flag++;
            if (_out) //_out用于判断找到正确答案的情况
            {
                printf("%llu", _min);
                return 0;
            }
        }
        if (tmp != 0 && tmp % m == 0)
        {
            tmp *= (LL)pow(10, ctr);
            if (tmp < _min) //在同一层bfs可能有许多个不同答案，题目需要最小的
                _min = tmp;
            _out = true;
            //printf("%lld", tmp);
            //break;
        }
        else 
        {
            for (LL i = 0; i < n; i++)
            {
                q.push(make_pair(i, tmp));  //bfs push下一层要检测的数据
            }
        }
        q.pop();
    }
}