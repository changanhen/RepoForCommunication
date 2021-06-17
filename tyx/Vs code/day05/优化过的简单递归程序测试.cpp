#include <stdio.h>
int factorial(int i)
{
	int An;
	if(i == 1)
		return(1);
	else
		An = 2 * factorial(i-1) + 1;
	return An; 
} 
int summation(int u)
{
	int sum;
	if(u == 0)
		return(0);
	else
		sum = factorial(u) + summation(u-1);
	return sum;
}
int main()
{
	int n;
	int result;
	int sum;
	while(n<=0)
	{
		printf("请输入n值：");
		scanf("%d", &n);
		if(n<=0)
			printf("n必须是大于0的整数！请重新输入！\n");
		else
			printf("正在计算中......\n");
	}
	result = factorial(n);
	sum = summation(n);
	if(n == 31)
		printf("第n项值为：%d\n前n项和超出计算范围！", result);
	else
		if(sum<=0)
			printf("超出计算范围！");
		else
		{
			printf("第n项值为：%d\n", result);
			printf("前n项和为：%d", sum);
		}
	return 0;
}
