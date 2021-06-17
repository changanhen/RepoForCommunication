#include<stdio.h>
#include<string.h>

void StrBubbleBetween(char* str, int begin, int end);

int main()
{
	char inStr[200] = { 0 };
	(void)scanf("%s", inStr);
	StrBubbleBetween(inStr, 1, strlen(inStr) - 2);
	printf("%s", inStr);
	return 0;
}

void StrBubbleBetween(char* str, int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		for (int j = end; j > i; j--)
		{
			if (str[j] > str[j - 1])
			{
				char temp = str[j];
				str[j] = str[j - 1];
				str[j - 1] = temp;
			}
		}
	}
}