#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	scanf("%c", &ch);
	ch = (ch>='A'&&ch<='Z')?putchar(tolower(ch)):putchar(ch);
	return 0;
}
