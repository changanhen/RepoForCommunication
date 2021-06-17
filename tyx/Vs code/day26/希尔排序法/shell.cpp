void shell(int data[], int size)
{
	int i;		/*i为扫描次数*/
	int j;		/*以j来定位比较的元素*/
	int k = 1;	/*k打印计数*/
	int tmp;	/*tmp用来暂存数据*/
	int jmp;	/*设定位间距位移量*/
	jmp = size / 2;
	while (jmp != 0)
	{
		for (i = jmp; i < size; i++)
		{
			tmp = data[i];
			j = i - tmp;
			while (tmp < data[j] && j >= 0)	/*插入排序法*/
			{
				data[j + jmp] = data[j];
				j = j - jmp;
			}
			data[jmp + j] = tmp;
		}
		jmp = jmp / 2;	/*控制循环数*/
	}
}