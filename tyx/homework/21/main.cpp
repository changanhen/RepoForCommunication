#include <stdio.h>
int main()
{
  int array[100] = { 0 }, statics[5] = { 0 }, i = 0;
  do
  {
    scanf("%d", array + i);
    i++;
  } while (array[i - 1] != -1);
  for (i = 0; array[i] != -1; i++)
  {
    switch (array[i])
    {
      case 0 :
        statics[0]++; break;
      case 1 :
        statics[1]++; break;
      case 2 :
        statics[2]++; break;
      case 3 :
        statics[3]++; break;
      case 4 :
        statics[4]++; break;
    }
  }
  for (i = 0; i < 5; i++)
  {
    if (i == 0)
      printf("%d", statics[i]);
    else
      printf(" %d", statics[i]);
  }
}