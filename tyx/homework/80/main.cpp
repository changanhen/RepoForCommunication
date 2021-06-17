#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    void ch_bbl(char storage[], int length);
    char arr1[101] = {0}, arr2[101] = {0}, storage[202] = {0}, array[202] = {0};
    int ion = 1, ctr = 0;
    scanf("%s%s", arr1, arr2);
    strcpy(array, arr1);
    strcat(array, arr2);
    /*for (int i = 0; array[i]; i++)
        array[i] = toupper(array[i]);*/
    _strupr(array);
    for (int i = 0; i < strlen(array); i++)
    {
        for (int j = 0; j < ctr; j++)
        {
            if (array[i] == storage[j])
            {
                ion = 0;
                break; //为了降低运行时间，这里用了break，实际上为了省事可以不写这个break
            }
        }
        if (ion)
        {
            storage[ctr++] = array[i];
        }
        ion = 1;
    }
    ch_bbl(storage, ctr);
    printf("%s", storage);
}
void ch_bbl(char storage[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (storage[j] > storage[j + 1])
            {
                char tmp = storage[j];
                storage[j] = storage[j + 1];
                storage[j + 1] = tmp;
            }
        }
    }
}