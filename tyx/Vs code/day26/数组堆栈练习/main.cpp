#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* create();
	int isEmpty(int top);
	int push(int data, int* ptr_top, int* stack);
	int pop(int* ptr_top, int stack[]);
	void scan(int* ptr_top, int stack[]);
	int i = 0, top = -1, data = 0;
	int* ptr_stack, * ptr_top = &top;
	ptr_stack = create();
	do
	{
		printf("要压入堆栈，请输入1，弹出则输入0，停止操作则输入-1：");
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:
			printf("请输入元素值：");
			scanf_s("%d", &data);
			push(data, ptr_top, ptr_stack);
			break;
		case 0:
			data = pop(ptr_top, ptr_stack);
			data == -1 ? printf("堆栈已空\n") : printf("弹出的元素为：%d\n", data);
			break;
		default:
			break;
		}
	}while (i != -1);
	printf("============================\n");
	scan(ptr_top, ptr_stack);
	printf("==========================\n");
	free(ptr_stack);
	return 0;
}