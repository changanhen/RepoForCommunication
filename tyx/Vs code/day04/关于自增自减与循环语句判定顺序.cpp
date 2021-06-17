#include <stdio.h>
int main()
{
	int x = 3;
	while (x--){
		printf("1");
	}
	return 0;
}
/* 结论：先判断x是否为零再进行自减，具有顺序性，写成--x会输出不同结果 */ 
