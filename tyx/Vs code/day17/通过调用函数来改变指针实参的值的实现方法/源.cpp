#include <stdio.h>
int main()
{
	void swap(int* p1, int* p2);
	int a, b;
	int* pointer_1, * pointer_2;
	scanf_s("%d,%d", &a, &b);
	pointer_1 = &a;
	pointer_2 = &b;
	if (a < b)
		swap(pointer_1, pointer_2);
	printf("max=%d, min=%d\n", a, b);
	return 0;
}
void swap(int* p1, int* p2)
{
	int* p;
	p = &*p1;
	&*p1 = &*p2;
	&*p2 = p;
	/*出现报错。结论：地址是无法修改的，只能改变地址上变量的值。在调用函数时，实参会被赋给形参并存储在新的地址，并且这个新的地址是可以存储另一变量的地址的。
	所以如果我用指针*来指向形参（此时代表另一变量的地址），就可以找到存储的原变量，并且修改该变量，此时可以通过&*再次取到该原变量的地址。
	虽然但是，实验证明，地址无法被修改。*/
}