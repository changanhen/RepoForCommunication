#include <bits/stdc++.h>

using namespace std;

int main() {
    double n;
    cin >> n;
    double signal = 1;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (signal / (2 * i - 1));
        signal = -signal;
    }
    printf("%.7lf", 4 * sum);
}