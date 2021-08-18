#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double sum = 0;
    //cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        //cin >> tmp;
        scanf("%d", &tmp);
        sum += tmp;
    }
    //cout << sum / (double)n;
    printf("%.5lf", sum / (double)n);
}