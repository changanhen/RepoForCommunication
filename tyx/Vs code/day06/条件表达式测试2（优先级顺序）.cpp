#include <stdio.h>
int main()
{
	int a, b, c, d, max, result;
	a = 2;
	b = 1;
	max = (a>b)?c = 2*a*b:d = 3*a*b;
	printf("max = %d\n", max);
	printf("d = %d\n", d);
	result = (a<b)?c = 4*a*b:d = 3*a*b;
	printf("result = %d\n", result);
	printf("c = %d\n", c);
	printf("d = %d\n", d);
	return 0;
}
