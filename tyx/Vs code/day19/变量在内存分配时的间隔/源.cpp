#include <stdio.h>
int main()
{
	char a, b, c;
	char* ptr_a = &a, * ptr_b = &b, * ptr_c = &c;
	printf("a的地址是：%d\nb的地址是：%d\nc的地址是：%d\n", ptr_a, ptr_b, ptr_c);
	return 0;
}