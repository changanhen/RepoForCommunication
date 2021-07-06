#include <stdio.h>
int main(){
    long long int a, b, p, mtp;
    scanf("%ld%ld%ld", &a, &b, &p);
    mtp = a * b;
    while (mtp - p >= 0)
        mtp -= p;
    printf("%ld", mtp);
}