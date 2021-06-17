#include<stdio.h>
#include<string.h>

char* DelCharBetweenStr(char* str, int i, int j, char delch);

int main()
{
	char inputStr[100];
	gets_s(inputStr,100);
	//找字符串左边第一个非空格字符
	int i = 0;
	while (inputStr[i] && inputStr[i] == ' ')
	{
		i++;
	}

	//找字符串右边第一个非空格字符
	int j = strlen(inputStr) - 1;
	while (inputStr[j] && inputStr[j] == ' ')
	{
		j--;
	}
	printf("%s", DelCharBetweenStr(inputStr, i, j, ' '));
	return 0;
}

char* DelCharBetweenStr(char* str, int i, int j, char delch)
{
	//删除i到j之间所有字符；
	while (j >= i)
	{
		if (str[j] == delch)
		{
			int n = j;
			while (str[n])
			{
				str[n] = str[n + 1];
				n++;
			}
			str[n] = 0;
		}
		j--;
	}
	return str;
}