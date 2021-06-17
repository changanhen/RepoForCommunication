#include <stdio.h>
#include <time.h>
int main()
{
	double duration;
	clock_t start, finish;
	int i;
	int bubble_sort2(int data[], int n);
	int data[8];
	start = clock();
	printf("ÇëÊäÈë8¸öÊı£º");
	scanf_s("%d %d %d %d %d %d %d %d", data, data + 1, data + 2, data + 3, data + 4, data + 5, data + 6, data + 7);
	bubble_sort2(data, 8);
	finish = clock();
	for (i = 0; i < 8; i++)
	{
		printf("data[%d]:%d ", i, data[i]);
	}
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n%g", duration);
}