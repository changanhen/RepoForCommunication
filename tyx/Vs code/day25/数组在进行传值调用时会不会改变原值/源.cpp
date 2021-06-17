#include <stdio.h>
int add(int data[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		data[i] = data[i] + 1;
	}
	for (i = 0; i < 5; i++)
	{
		printf("#%d ", data[i]);
	}
	printf("\n");
	return 0;
}
int main()
{
	int i;
	int data[5] = { 1,2,3,4,5 };
	for (i = 0; i < 5; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	add(data);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", data[i]);
	}
}
//结论：数组在传值调用时会改变原值，因为本质上传的是数组首元素地址，相当于回调函数。