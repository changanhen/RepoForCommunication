#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;
/**
 * @brief long long int PAIR
 * @param <该位数，当前和>
 */
typedef pair<LL, LL> PAIR;

int main() {
    LL n, m, ctr = 0, flag = 0, flag_ft = 0, layer = 0, layer_counter = 0;
    LL _min = 9223372036854775807;
    bool _out = false;
    scanf("%lld%lld", &n, &m);
    while (m % 10 == 0)
    {
        m /= 10;
        ctr++;
    }
    queue<PAIR> q;
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
    while (!q.empty())
    {
        PAIR P = q.front();
        LL tmp = P.first * (LL)pow(10, flag) + P.second;
        if (P.first == flag_ft)
        {
            flag++;
            //layer *= n;
            flag_ft = -1;
        }
        else if (P.first == n - 1)
            layer_counter++;
        if (layer_counter == layer)
        {
            layer *= n;
            layer_counter = 0;
            flag++;
            if (_out)
            {
                printf("%lld", _min);
                return 0;
            }
        }
        if (tmp != 0 && tmp % m == 0)
        {
            tmp *= (LL)pow(10, ctr);
            if (tmp < _min)
                _min = tmp;
            _out = true;
            //printf("%lld", tmp);
            //break;
        }
        else 
        {
            for (LL i = 0; i < n; i++)
            {
                q.push(make_pair(i, tmp));
            }
        }
        q.pop();
    }
}