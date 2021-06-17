/*#include <stdio.h>
int main()
{
    int votes[4], per[100];
    scanf("%d", per);
    for (int i = 1; per[i-1] != -1; i++)
    {
        scanf("%d", per + i);
    }
    for (int i = 0; per[i] != -1; i++)
    {
        if (per[i] >= 1 && per[i] <= 3)
            votes[per[i]]++;
        else
            votes[0]++;
    }
    for (int i = 1; i < 4; i++)
    {
        printf("%d ", votes[i]);
    }
    printf("%d", votes[0]);
}
#include <stdio.h>
int main()
{
    int votes[4] = { 0 }, per;
    while ((per = getchar()) != '\n')
    {
        if (per == '1' || per == '2' || per == '3')
            votes[per - 48]++;
        else if (per != ' ' && per != '-')
            votes[0]++;
        if (per >= 10 && per <= 19)
            votes[1]--;
    }
    for (int i = 1; i < 4; i++)
    {
        i == 1?printf("%d ", votes[i] - 1): printf("%d ", votes[i]);
    }
    printf("%d", votes[0]);
}*/
#include <stdio.h>
int main()
{
	int count[4] = {0};
	int n;
	(void)scanf("%d", &n);
	while (n != -1)
	{
		n >= 1 && n <= 3 ? count[n]++ : count[0]++;
		(void)scanf("%d", &n);
	}
	printf("%d %d %d %d", count[1], count[2],
	       count[3], count[0]);
	return 0;
}