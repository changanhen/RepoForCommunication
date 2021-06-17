#include <stdio.h>
#include <time.h>
#define N 1000000000
#define M 2147483647
int main()
{
	clock_t start, finish;
	double duration;
	start = clock();
	int a = 100000;
	for (long long int i = 0; i < N; i++)
	{
		a ^= 53736;
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Times: %lf", duration);
}