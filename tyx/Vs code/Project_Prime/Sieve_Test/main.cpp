/*
埃氏筛法（快速筛选n以内素数的个数）
*/
#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 1e7;

int prime[N];//第i个素数
bool is_prime[N];//true表示i是素数

int Ans(int n){
    int i, j, k;
    k = 0;
    //memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;//预处理0和1,0和1不是素数
    for(i = 2; i <= n; i++){
        if(is_prime[i]){///当前i是一个素数，则他的倍数皆不是素数
            prime[k++] = i;//计算素数的个数，同时记录素数本身
            for(j = 2*i; j <= n; j += i){//筛掉素数的倍数的数
                is_prime[j] = false;
            }
        }
    }
    return k;//返回n以内素数的个数
}

int main(){
    int n, i, ans;
    while(cin >> n){
        ans = Ans(n);
        cout << ans << endl;//输出素数的个数
        for(i = 0; i < ans; i++){
            cout << prime[i] << endl;//输出素数本身
        }
    }
    return 0;
}