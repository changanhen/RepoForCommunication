#include <stdio.h>
void quick(int d[], int size, int lf, int rg)
{
	int i, j, tmp;
	int lf_idx;
	int rg_idx;
	int t;
	int process = 0;
				/*1:第一个键值为d[lf]*/
	if (lf < rg)
	{
		lf_idx = lf + 1;
		rg_idx = rg;
step2:
		printf("[处理过程%d]=> ", process++);
		for (t = 0; t < size; t++)
			printf("[%2d] ", d[t]);
		printf("\n");
		for (i = lf + 1; i <= rg; i++)	/*2:从左向右找出一个键值大于d[lf]者*/
		{
			if (d[i] >= d[lf])
			{
				lf_idx = i;
				break;
			}
			lf_idx++;
		}
		for (j = rg; j >= lf + 1; j--)	/*3:从右向左找出一个键值小于d[lf]者*/
		{
			if (d[j] <= d[lf])
			{
				rg_idx = j;
				break;
			}
			rg_idx--;
		}
		if (lf_idx < rg_idx)				/*4-1:若lf_idx<rg_idx*/
		{									/*则d[lf_idx]和d[rg_idx]互换*/
			tmp = d[lf_idx];
			d[lf_idx] = d[rg_idx];
			d[rg_idx] = tmp;
			goto step2;						/*4-2:并继续执行步骤2*/
		}
		if (lf_idx >= rg_idx)				/*5-1:若if_idx大于等于rg_idx*/
		{									/*则将d[lf]和d[rg_idx]互换*/
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
						/*5-2:并以rg_idx为基准点分成左右两半*/
			quick(d, size, lf, rg_idx - 1);	/*以递归方式分别为左右两半进行排序*/
			quick(d, size, rg_idx + 1, rg);	/*直至完成排序*/
		}
	}
}