#include <stdio.h>
#include <string.h>
typedef struct Word
{
    char chs[21];
} word;
typedef struct scs
{
    char store[21];
    int times;
} statics;

int main()
{
    word array[101];
    int ctr = 0, ctr2 = 0, ion = 1;
    do
    {
        scanf("%s", &array[ctr++].chs);
    } while (strcmp(array[ctr - 1].chs, "###"));
    statics storage[101];
    for (int i = 0; i < 101; i++)
    {
        storage[i].store[0] = 0;
        storage[i].times = 1;
    }
    for (int i = 0; i < ctr; i++)
    {
        for (int j = 0; j < ctr2; j++)
        {
            if (strcmp(array[i].chs, storage[j].store) == 0)
            {
                storage[j].times++;
                ion = 0;
                break;
            }
        }
        if (ion)
            strcpy(storage[ctr2++].store, array[i].chs);
        ion = 1;
    }
    for (int i = 0; strcmp(storage[i].store, "###"); i++)
    {
        i ? printf(" %s-%d", storage[i].store, storage[i].times) : printf("%s-%d", storage[i].store, storage[i].times);
    }
}