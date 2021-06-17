#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	while (a = --b)//先自减，再赋值，最后判断
	{
		printf("%d, %d\n", a, b);
	}
	while (a = b--)//先赋值，再自增，最后判断，这是根据上面推出的更合理的猜想，目前实验数据都表明，如果先赋值，再判断，最后自增，也是合理的。
	{
		printf("%d, %d\n", a, b);
	}
}