#include <stdio.h>
int main()
{
	int a, b;
	char max;
	max = (a>b)?scanf("%d", &a):scanf("%d", &b);
	max = (a>b)?a:b;
	printf("max = %c", max);
	return 0;
}
