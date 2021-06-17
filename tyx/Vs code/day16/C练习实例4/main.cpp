/*题目：输入某年某月某日，判断这一天是这一年的第几天？
程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天。*/
#include <stdio.h>
int main()
{
	int detective(int year);
	int monthday(int year, int month, int day);
	int year, month, day, sum;
	printf("请输入年月日：");
	scanf_s("%d %d %d", &year, &month, &day);
	if (monthday(year, month, day) == -1)
		printf("无效的月份");
	else
	{
		if (day <= 0 || monthday(year, month, day) == -2)
			printf("无效的日期");
		else
		{
			sum = monthday(year, month, day) + day;
			if (detective(year) && month > 2)
				sum = sum + 1;
			printf("这一天是这一年的第%d天", sum);
		}
	}
	return 0;
}