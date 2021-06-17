int selection_sort(int data[], int n)
{
	int i, j, tmp, k;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n + 1; j++)
		{
			if (data[i] > data[j])
			{
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
	return 0;
}