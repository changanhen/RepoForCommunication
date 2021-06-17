#include <stdio.h>
int main()
{
    void dg_bbl(int storage[], int length);
    int len1, len2, arr1[100], arr2[100], storage[100], ion = 1, ctr = 0;
    scanf("%d", &len1);
    for (int i = 0; i < len1; i++)
    {
        scanf("%d", arr1 + i);
    }
    scanf("%d", &len2);
    for (int i = 0; i < len2; i++)
    {
        scanf("%d", arr2 + i);
    }
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (arr1[i] == arr2[j])
                ion = 0;
        }
        if (ion)
            storage[ctr++] = arr1[i];
        ion = 1;
    }
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (arr2[i] == arr1[j])
                ion = 0;
        }
        if (ion)
        {
            storage[ctr++] = arr2[i];
        }
        ion = 1;
    }
    dg_bbl(storage, ctr);
    for (int i = 0; i < ctr; i++)
    {
        i ? printf(" %d", storage[i]) : printf("%d", storage[i]);
    }
}
void dg_bbl(int storage[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (storage[j] > storage[j + 1])
            {
                int tmp = storage[j];
                storage[j] = storage[j + 1];
                storage[j + 1] = tmp;
            }
        }
    }
}