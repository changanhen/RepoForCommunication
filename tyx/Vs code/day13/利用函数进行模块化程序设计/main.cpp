#include <stdio.h>
int main()
{
	int max4(int a, int b, int c, int d);
	int a, b, c, d, max;
	printf("Please enter 4 interger numbers:");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	max = max4(a, b, c, d);
	printf("max = %d \n", max);
	return 0;
}