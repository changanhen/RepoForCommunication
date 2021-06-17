#include <stdio.h>
int main()
{
	void hanoi(int, int, int, int);
	int n;
	printf("ÇëÊäÈëÅÌ×ÓÊı£º");
	scanf_s("%d", &n);
	hanoi(n, 1, 2, 3);
	return 0;
}