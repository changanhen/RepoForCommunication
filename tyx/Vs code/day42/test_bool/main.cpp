#include <stdio.h>
#include <stdbool.h>
int main()
{
    char a[2077004];
    int b = 1, c = 2;
    for (int i = 0; i < 10; i++)
    {
        a[i] = b;
    }
    char* ptr;
    for (int i = 0; i < 10; i++)
    {
        ptr = &a[i];
        printf("%d\n", ptr); 
    }
    
}