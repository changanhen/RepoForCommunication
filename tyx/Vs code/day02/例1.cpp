#include <stdio.h>
float x;
int y;
int main()
{
	printf("enter x:");
	scanf("%f", &x);
	if(x<0)
		y = -1;
	else
		if(x==0)
			y = 0;
		else
			y = 1;
	if(x<=0)
		if(x==0)
			y = 0;
		else
			y = -1;
	else
		y = 1;
	printf("x = %g\ny = %d", x, y);
	return 0;
 }
