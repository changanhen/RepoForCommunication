#include <stdio.h>
void radix(int data[], int size)
{
	int i, j, k, n, m;
	for (n = 1; n <= 100; n = n * 10)	/* n为基数，从个位数开始排序 */
	{
		int tmp[10][100] = { 0 };
/* 设置暂存数组，[0～9位数][数据个数]，所有内容均为0 */
		for (i = 0; i < size; i++)
		{
			m = (data[i] / n) % 10;
/* m为n位数的值，如36取十位数 (36/10)%10=3 */
			tmp[m][i] = data[i];/* 把data[i]的值暂存于tmp里 */
		}
		k = 0;
		for ( i = 0; i < 10; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (tmp[i][j] != 0)
					/* 因一开始设置tmp={0}，故不为0者即为 */
				{
					data[k] = tmp[i][j];
					/* data暂存在tmp里的值，把tmp里的值放 */
					k++;								/* 回data[ ]里 */
				}
			}
		}
		printf("经过%3d位数排序后：", n);
		//showdata(data, size);
	}
}