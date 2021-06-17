#include <stdio.h>
#include <stdlib.h>
int main()
{
	float* piVal = (float*)malloc(sizeof(float));
	*piVal = 3.14159;
	int* piCal = (int*)malloc(sizeof(int));
	*piCal = 1000;
	printf("piVal 所指向的地址内容为 %f\n\n", *piVal);
	printf("piCal 所指向的地址内容为 %d\n\n", *piCal);
	free(piVal);
	free(piCal);
	return 0;
}