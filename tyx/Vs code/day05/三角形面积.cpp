#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,s,area;
	printf("请输入三边长度：");
	scanf("%f %f %f", &a, &b, &c); 
	if(a+b>c&&b+c>a&&c+a>b)
  	{
  	 s = 0.5*(a+b+c);
  	 area = sqrt(s*(s-a)*(s-b)*(s-c));
  	 printf("area = %6.2f", area);
  	}
	else
	printf("it is not a trilateral");
	return 0;
}
