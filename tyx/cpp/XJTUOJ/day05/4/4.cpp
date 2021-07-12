#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> PAIR;

int main() {
    int n, tmp, ans = 1;
    scanf("%d", &n);
    PAIR* arr = (PAIR*)malloc(n * sizeof(PAIR));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        arr[i - 1] = make_pair(tmp, i);
    }
    sort(arr, arr + n);
    stack<PAIR> st, _max;
    st.push(arr[0]);
    _max = st;
    for (int i = 1; i < n; i++)
    {
        PAIR _old = st.top();
        PAIR _new = arr[i];
        while (_new.first < _old.first || _new.second <= _old.second)
        {
            st.pop();
            if (!st.empty())
                _old = st.top();
            else
                break;
        }
        st.push(_new);
        tmp = st.size();
        if (tmp > ans)
        {
            ans = tmp;
            _max = st;
        }
    }
    for (int i = 0; i < ans; i++)
    {
        arr[i] = _max.top();
        _max.pop();
    }
    printf("%d\n", ans);
    for (int i = ans - 1; i >= 0; i--)
    {
        i == 0 ? printf("%d", arr[i].second) : printf("%d ", arr[i].second);
    }
}