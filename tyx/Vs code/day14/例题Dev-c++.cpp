#include <stdio.h>
int ageadd(int n)
{
	int c;
	if (n == 1)
		c = 10;
	else
		c = ageadd(n - 1) + 2;
	return (c);
}
int main()
{
	printf("The age of 5th student is %d", ageadd(5));
	return 0;
}
