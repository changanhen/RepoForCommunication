#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp;
    fp = fopen("yl.txt", "w");
    for (int i = 1; i <= 200000; i++)
    {
        fprintf(fp, "%d %d\n", i, i);
    }
}