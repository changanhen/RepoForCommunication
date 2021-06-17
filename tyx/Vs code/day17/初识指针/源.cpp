#include <stdio.h>
int main()
{
	int i = 0;
	int* pointer_i;
	pointer_i = &i;
	printf("%p", pointer_i);
	return 0;
}