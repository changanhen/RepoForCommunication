#include <stdio.h>
#include <time.h>
#define N 200000
int main()
{
	clock_t start, finish;
	double duration;
	start = clock();
	int array[N];
	for (int i = 0; i < N; i++)
	{
		array[i] = 200000;
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("RunningTime: %lf", duration);
}