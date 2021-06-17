#include <stdio.h>
int main()
{
	char c[11]={'I','\0','a','m'};
	int i;
	for(i=0;i<11;i++) 
		printf("%c",c[i]);
	printf("\n");
	return 0;
}
