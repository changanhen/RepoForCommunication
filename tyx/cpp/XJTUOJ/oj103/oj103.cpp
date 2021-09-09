#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int year;
    int month;
    cin >> year >> month;
    cout << year << ' ' << month << ' ';
    map<int, int> mp;
    mp[1] = 31;
    mp[2] = 28;
    mp[3] = 31;
    mp[4] = 30;
    mp[5] = 31;
    mp[6] = 30;
    mp[7] = 31;
    mp[8] = 31;
    mp[9] = 30;
    mp[10] = 31;
    mp[11] = 30;
    mp[12] = 31;
    if (month != 2)
        cout << mp[month];
    else 
    {
        if (year % 4 == 0 && year % 100 || year % 400 == 0)
            cout << mp[2] + 1;
        else
            cout << mp[2];
    }
}