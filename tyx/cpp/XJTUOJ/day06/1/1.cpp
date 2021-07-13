#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef struct hole {
    LL x, y, z, r;
    LL belong;
} Hole;

int main() {
    LL n;
    LL _x, _y, _z, _r, ctr = 0;
    scanf("%lld", &n);
    Hole arr[5005];
    for (LL i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld%lld", &_x, &_y, &_z, &_r);
        arr[i].x = _x;
        arr[i].y = _y;
        arr[i].z = _z;
        arr[i].r = _r;
        arr[i].belong = i;
    }
    for (LL i = 0; i < n - 1; i++)
    {
        for (LL j = i + 1; j < n; j++)
        {
            LL dx = arr[i].x - arr[j].x;
            LL dy = arr[i].y - arr[j].y;
            LL dz = arr[i].z - arr[j].z;
            LL distance2 = dx * dx + dy * dy + dz * dz;
            LL dr = arr[i].r + arr[j].r;
            LL r2 = dr * dr;
            if (r2 > distance2)
            {
                if (arr[j].belong > arr[i].belong)
                    arr[j].belong = arr[i].belong;
                else
                    arr[i].belong = arr[j].belong;
            }
            /*if (r2 > distance2)
            {
                if (arr[j].belong != -1)
                    arr[i].belong = arr[j].belong;
                else
                {
                    arr[i].belong = ctr;
                    ctr++;
                    arr[j].belong = arr[i].belong;
                }
            }
            else if (arr[i].belong == -1)
            {
                arr[i].belong = ctr;
                ctr++;
            }*/
        }
    }
    for (LL i = 0; i < n; i++)
    {
        if (arr[i].belong == i)
            ctr++;
    }
    printf("%lld", ctr - 1);
    /*if (arr[n - 1].belong == -1)
        ctr++;
    prinf("%d", ctr - 1);*/
}