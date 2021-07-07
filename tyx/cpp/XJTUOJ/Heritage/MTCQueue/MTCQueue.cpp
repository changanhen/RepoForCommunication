#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    priority_queue <int, vector<int>, greater<int> > q;
    int n, m, k, tmp;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n + m; i++)
    {
        scanf("%d", &tmp);
        q.push(tmp);
    }
    for (int i = 0; i < k; i++)
    {
        tmp = q.top();
        q.pop();
    }
    printf("%d", tmp);
}