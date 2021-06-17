#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct _rational
{
	int numerator;	 //分子
	int denominator; //分母
} Rational;

Rational Add(Rational x, Rational y);
int Gcd(int x, int y);

int main()
{
	int n;
	Rational sum = {0, 1};
	Rational x;
	(void)scanf("%d", &n);
	char ch;
	for (int i = 0; i < n; i++)
	{
		//ch是读入的除号
		//也可以写为
		//(void)scanf("%d/%d",&x.numerator, &x.denominator);
		//这样写不需要ch
		(void)scanf("%d%c%d", &x.numerator, &ch, &x.denominator);
		sum = Add(sum, x);
	}

	//输出
	if (sum.numerator < 0) //负数的情况
	{
		printf("-");
		sum.numerator = -sum.numerator;
	}
	if (sum.denominator == 1) //只有整数部分
	{
		printf("%d", sum.numerator);
	}
	else
	{
		if (sum.numerator > sum.denominator) //整数分数都有
		{
			int integer = sum.numerator / sum.denominator;
			sum.numerator = sum.numerator - sum.denominator * integer;
			printf("%d %d/%d", integer, sum.numerator, sum.denominator);
		}
		else //只有分数部分
		{
			printf("%d/%d", sum.numerator, sum.denominator);
		}
	}
	return 0;
}

/// <summary>
/// 将2个分数加起来求和
/// </summary>
/// <param name="x">加数</param>
/// <param name="y">被加数</param>
/// <returns>和</returns>
Rational Add(Rational x, Rational y)
{
	Rational z; //通分相加
	z.denominator = x.denominator * y.denominator;
	z.numerator = x.denominator * y.numerator + x.numerator * y.denominator;

	//求分子分母的最大公约数
	int gcd = Gcd(z.denominator, z.numerator);
	//约分
	z.denominator = z.denominator / gcd;
	z.numerator = z.numerator / gcd;
	return z;
}

/// <summary>
/// 求2个数的最大公约数
/// </summary>
/// <param name="x">数1</param>
/// <param name="y">数2</param>
/// <returns>最大公约数</returns>
int Gcd(int x, int y)
{
	int gcd = x;
	while (x % gcd || y % gcd)
	{
		gcd--;
	}
	return gcd;
}