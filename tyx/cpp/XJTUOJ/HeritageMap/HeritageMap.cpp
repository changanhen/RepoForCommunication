#include <map>
#include <iostream>
using namespace std;
map<long double, pair<long double, long double>, greater<long double>> territory;
int main(){
    int n;
    scanf("%d", &n);
    long double numerator, denominator, value;
    /*for (int i = 0; i < n; i++)
    {
        scanf("%llf%llf", &numerator, &denominator);
        value = numerator / denominator;
        territory[value] = make_pair(numerator, denominator);
    }*/
    for (auto a:territory)
    {
        scanf("%llf%llf", &numerator, &denominator);
        value = numerator / denominator;
    }
    /*for (map<long double, pair<long double, long double>>::iterator iter = territory.begin(); iter != territory.end(); ++iter)
    {
        cout << iter->second.first << iter->second.second << endl;
    }*/
    /*for (auto p : territory)
    {
        cout << (p.second).first << "/" << (p.second).second << endl;
    }*/
    for (auto p:territory)
    {
        printf("%d/%d\n", (int)(p.second).first, (int)(p.second).second);
    }
    return 0;
}