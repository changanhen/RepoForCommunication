#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	if(isalpha(ch = getchar()))
	{
		ch = ch+4;
		if(ch>'Z'&&ch<='Z'+4||ch>'z')
			ch = ch-26;
			printf("%c", ch);
		else
			printf("%c", ch);
	}
	else
		printf("%c", ch);
	return 0;
}
