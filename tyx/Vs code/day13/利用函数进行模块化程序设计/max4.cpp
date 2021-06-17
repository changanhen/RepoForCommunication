int max4(int a, int b, int c, int d)
{
	int max2(int, int);
	int m;
	m = max2(a, b);
	m = max2(m, c);
	m = max2(m, d);
	return m;
}