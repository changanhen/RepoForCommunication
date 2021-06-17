#include <stdio.h>
int getlength(char array[])
{
	int length;
	length = sizeof(array) / sizeof(array[0]);
	return length;
}
int main()
{
	char array[5];
	char* ptr;
	int length;
	length = getlength(array);
	printf("%d\n", length);
	length = sizeof(ptr);
	printf("%d", length);
	return 0;
}