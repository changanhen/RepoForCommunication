#include <stdio.h>
int main()
{
	int data[8];
	int selection_sort(int data[], int n);
	printf("ÇëÊäÈë8¸öÊı£º");
	scanf_s("%d %d %d %d %d %d %d %d", data, data + 1, data + 2, data + 3, data + 4, data + 5, data + 6, data + 7);
	selection_sort(data, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", data[i]);
	}
}