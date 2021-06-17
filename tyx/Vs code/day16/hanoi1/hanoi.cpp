#include <stdio.h>
void hanoi(int n, int p1, int p2, int p3)
{
	if (n == 1)
		printf("盘子从 %d 移到 %d\n", p1, p3);
	else
	{
		hanoi(n - 1, p1, p3, p2);
		printf("盘子从 %d 移到 %d\n", p1, p3);
		hanoi(n - 1, p2, p1, p3);
	}
}