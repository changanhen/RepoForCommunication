#include <stdio.h>
int main()
{
	char string[81];
	int i, num=0;
	printf("Please enter a line:");
	gets(string);
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] != ' ' && (string[i + 1] == ' '||string[i+1]=='\0'))
			num++;
	}
	printf("There are %d words in this line.\n", num);
	return 0;
}
