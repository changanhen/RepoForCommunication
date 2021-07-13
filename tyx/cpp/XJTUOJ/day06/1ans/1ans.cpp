//
//  main.cpp
//  A
//
//  Created by apple on 2021/7/13.
//并查集
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct node
{
    int x, y, z, r;
    int fa;
} point[5005];
int n;
int find(int a);
void merge(int a, int b);
bool solve(int a, int b);
int main()
{
    int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &point[i].x, &point[i].y, &point[i].z, &point[i].r);
        point[i].fa = i;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (solve(i, j))
                merge(i, j);

    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            ans++; //,cout<<i<<endl;
    cout << ans - 1;
}
int find(int a)
{
    if (point[a].fa == a)
        return a;
    else
        return point[a].fa = find(point[a].fa);
}
void merge(int a, int b)
{
    point[find(a)].fa = find(b);
}
bool solve(int a, int b)
{
    int dx = point[a].x - point[b].x;
    int dy = point[a].y - point[b].y;
    int dz = point[a].z - point[b].z;
    double dis = sqrt(dx * dx + dy * dy + dz * dz);
    //cout<<a<<" "<<b<<" "<<dis<<" "<<point[a].r+point[b].r<<endl;
    if (dis >= point[a].r + point[b].r)
        return false;
    else
        return true;
}
