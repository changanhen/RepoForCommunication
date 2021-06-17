#include <stdio.h>

typedef struct _rational
{
    int numerator;
    int denominator;
} rational;

int main()
{
    rational add(rational sum, rational x);
    int gcd(int a, int b);
    int n, digit = 0;
    rational sum = {0, 1};
    rational x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d/%d", &x.numerator, &x.denominator);
        sum = add(sum, x);
    }
    if (sum.numerator / sum.denominator)
    {
        digit = sum.numerator / sum.denominator;
        sum.numerator %= sum.denominator;
    }
    if (sum.numerator < 0 && digit < 0)
        sum.numerator = -sum.numerator;
    if (digit)
        if (sum.numerator)
            printf("%d %d/%d", digit, sum.numerator, sum.denominator);
        else
            printf("%d", digit);
    else if (sum.numerator)
        printf("%d/%d", sum.numerator, sum.denominator);
    else
        printf("0");
}

rational add(rational sum, rational x)
{
    int gcd(int a, int b);
    rational z;
    int lcm = sum.denominator * x.denominator / gcd(sum.denominator, x.denominator);
    z.denominator = lcm;
    z.numerator = sum.numerator * lcm / sum.denominator + x.numerator * lcm / x.denominator; //样例4 -15/437 -513/12 -65/35 -0/5在这里不能通过
    int tmp = z.denominator;                                                                 //原因是在加第三个数的时候，上一行的sum.numerator * lcm为-4575468660超出了整型变量的最大值2147483647，导致该值变小
    z.denominator /= gcd(z.numerator, z.denominator);                                        //所以还是不要这样用，干脆直接分子分母互乘，把值算完，最后再约分
    z.numerator /= gcd(z.numerator, tmp);
    return z;
    /*int gcd(int a, int b);
    rational z; //通分相加
	z.denominator = x.denominator * y.denominator;
	z.numerator = x.denominator * y.numerator + x.numerator * y.denominator;

	//求分子分母的最大公约数
	int Gcd = gcd(z.numerator, z.denominator);
	//约分
	z.denominator = z.denominator / Gcd;
	z.numerator = z.numerator / Gcd;
	return z;*/
}

int gcd(int a, int b)
{
    int Gcd = b;
    while (a % Gcd || b % Gcd)
        Gcd--;
    return Gcd;
}