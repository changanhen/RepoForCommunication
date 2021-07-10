//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef unsigned long long int LL;

class A
{
    public:
        LL A11, A12, A21, A22;
    void set(LL a, LL b, LL c, LL d);
    LL get();
    void mtp();
    void mod(LL p);
};

A pow_mod(A a, LL e, LL p);
A mtp2(A x, A y);

int main() {
    A a;
    a.set(1, 1, 1, 0);
    LL e, p;
    scanf("%llu%llu", &e, &p);
    A ans;
    if (e > 2)
        ans = pow_mod(a, e - 2, p);
    else 
    {
        printf("%llu", 2 % p);
        return 0;
    }
    LL tmp = ans.A11 + ans.A12;
    LL answer = ((2 % p) * tmp) % p;
    printf("%llu", answer);
    //printf("%lld", ans.A11 + ans.A12);
    return 0;
}

A pow_mod(A a, LL e, LL p) {
    if (e == 1)
        return a;
    A b = pow_mod(a, e / 2, p);
    if (e & 1)
    {
        b.mtp();
        b.mod(p);
        a.mod(p);
        b = mtp2(b, a);
        b.mod(p);
    }
    else 
    {
        b.mtp();
        b.mod(p);
    }
    return b;
}

A mtp2(A x, A y) {
    A c;
    c.A11 = x.A11 * y.A11 + x.A12 * y.A21;
    c.A12 = x.A11 * y.A12 + x.A12 * y.A22;
    c.A21 = x.A21 * y.A11 + x.A22 * y.A21;
    c.A22 = x.A21 * y.A12 + x.A22 * y.A22;
    return c;
}

void A::set(LL a, LL b, LL c, LL d) {
    A11 = a;
    A12 = b;
    A21 = c;
    A22 = d;
}

void A::mtp() {
    LL a11, a12, a21, a22;
    a11 = A11 * A11 + A12 * A21;
    a12 = A11 * A12 + A12 * A22;
    a21 = A21 * A11 + A22 * A21;
    a22 = A21 * A12 + A22 * A22;
    A11 = a11;
    A12 = a12;
    A21 = a21;
    A22 = a22;
}

void A::mod(LL p) {
    A11 %= p;
    A12 %= p;
    A21 %= p;
    A22 %= p;
}