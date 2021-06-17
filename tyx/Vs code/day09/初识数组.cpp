#include <stdio.h>
int main()
{
	int i, a[10];
	for (i=0;i<=9;i++)
		a[i]=i;
	for (i=9;i<=5;i--)
		printf("%d", a[i]);//说明：当初始值不在判断区间时会直接跳出循环 
	return 0;
}
