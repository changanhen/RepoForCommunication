#include <stdio.h>
#include <stdlib.h>
int* create()
{
	int* stack;
	int a[5] = { 0 };
	stack = (int*)malloc(sizeof(a));
	return stack;
}
int isEmpty(int top)
{
	if (top == -1) return 1;
	else return 0;
}
int push(int data, int* ptr_top, int* stack)
{
	if (*ptr_top >= 4)
	{
		printf("堆栈已满，无法再加入\n");
		return 0;
	}
	else
	{
		stack[++ * ptr_top] = data;
		return 1;
	}
}
int pop(int* ptr_top, int stack[])
{
	if (isEmpty(*ptr_top))
		return -1;
	else
	{
		int n = (*ptr_top)--;
		return stack[n];
	}
}
void scan(int* ptr_top, int stack[])
{
	int data = 0;
	while (*ptr_top > -1)
	{
		data = pop(ptr_top, stack);
		printf("堆栈弹出的顺序为：%d\n", data);
	}
}