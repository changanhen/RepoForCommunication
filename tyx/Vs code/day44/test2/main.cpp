#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	double duration;
	clock_t start, finish;
	start = clock();
	FILE* fp;
	fopen_s(&fp,"prime.txt", "w");
	int pri[100004] = { 0 };
	pri[0] = 1;
	pri[1] = 1;
	pri[2] = 0;
	int i = 0, p = 0, k = 0;
	for (p = 0; p < 100002; p++)
	{
		if (pri[p] == 0)
		{
			fprintf(fp, "%d\n", p);
			for (i = pri[p]; i < 100002; i++)
			{
				if (pri[i] == 1)
					continue;
				else
				{
					if (i % p == 0)
						pri[i] = 1;
				}
			}
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	fprintf(fp, "%f seconds\n", duration);
	return (int)duration;
}

