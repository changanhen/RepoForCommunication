int bubble_sort1(int data[], int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (data[j - 1] > data[j])
			{
				tmp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = tmp;
			}
		}
	}
	return 0;
}