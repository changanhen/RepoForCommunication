#include <stdio.h>
void merge(FILE* fp, FILE* fp1, FILE* fp2)
{
	int n1, n2;	/*声明变量n1, n2暂存数据文件data1和data2内的元素值*/
	n1 = getc(fp1);	/*从fp1中取一个元素进来，存在n1*/
	n2 = getc(fp2);
	while (feof(fp1) == 0 && feof(fp2) == 0)	/*判断是否已到文件尾*/
	{
		if (n1 <= n2)
		{
			putc(n1, fp);	/*如果n1比较小，则把n1存到fp里*/
			n1 = getc(fp1);	/*接着读下一项n1的数据*/
		}
		else
		{
			putc(n2, fp);	/*如果n2比较小，则把n2存到fp里*/
			n2 = getc(fp2);	/*接着读下一项n1的数据*/
		}
	}
	if (feof(fp1))	/*如果其中一个数据文件已读取完毕，经判断后*/
	{
		putc(n2, fp);	/*把另一个数据文件内的数据全部放到fp里*/
		while (1)
		{
			n2 = getc(fp2);
			if (feof(fp2)) break;
			putc(n2, fp);
		}
	}
	else if (feof(fp2))
	{
		putc(n1, fp);
		while (feof(fp1))
		{
			n1 = getc(fp1);
			putc(n1, fp);
		}
	}
}