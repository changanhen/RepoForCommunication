#include <stdio.h>
int main()
{
	int a, K, b = 0, d;
	char m[200], c;
	(void)scanf("%d%d", &a, &K);
	while (a)
	{
		d = a % K;
		if (d > 9)
		{
			c = d - 10 + 'A';
		}
		else { c = d + '0'; }
		m[b] = c;
		a = a / K;
		b++;
	}
	for (int i = b - 1; i >= 0; i--)
	{
		printf("%c", m[i]);
	}
	return 0;
}
