#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "China";
	int i,j;
	for (i=0;i<6;i++)
	{
		printf("%c", str[i]);
	}
	j = strlen(str);
	printf("%d", j);//字符串实际长度不包括\0在内
	return 0;
}