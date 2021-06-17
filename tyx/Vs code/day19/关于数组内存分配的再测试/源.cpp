#include <stdio.h>
int main()
{
	char a[2];
	char b[3];
	char c[5];
	char* ptr_a, * ptr_b, * ptr_c;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ptr_c = c + i;
		printf("c[%d]的地址是：%d\n", i, ptr_c);
	}
	for (i = 0; i < 3; i++)
	{
		ptr_b = b + i;
		printf("b[%d]的地址是：%d\n", i, ptr_b);
	}
	for (i = 0; i < 2; i++)
	{
		ptr_a = a + i;
		printf("a[%d]的地址是：%d\n", i, ptr_a);
	}
	return 0;
}