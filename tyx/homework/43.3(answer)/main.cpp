#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int inputNum[50];
	int i = 0;
	do
	{
		(void)scanf("%d", &inputNum[i]);
	}
	while (inputNum[i++]);
	
	int gcd = inputNum[0];
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int n = 0; n < i - 1; n++)
		{
			if (inputNum[n] % gcd)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			gcd--;
		}
	}
	printf("%d", gcd);
	for (int n = 0; n < i - 1; n++)
	{
		printf(" %d", inputNum[n]);
	}

	return 0;
}