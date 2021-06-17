#include <stdio.h>
int main()
{
	int i;
	char diamond[][5] = {{' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},{' ','*',' ','*'},{' ',' ','*'}};
	for(i=0;i<5;i++)
	{
		printf("%s\n", diamond[i]); 
	}
	return 0;
}
