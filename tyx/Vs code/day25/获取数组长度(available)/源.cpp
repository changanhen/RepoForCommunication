#include <stdio.h>
int main()
{
	char array[5] = {'\0'};
	int length;
	for (int i = 0; i < 5; i++)
	{
		printf("%c", array[i]);
	}
	printf("\n");
	length = sizeof(array) / sizeof(array[0]);
	printf("%d", length);
	return 0;
}