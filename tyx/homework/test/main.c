#include <stdio.h>
typedef bool __crt_bool;
int main()
{
    __crt_bool bl;
    int a = 1, b = 2;
    bl = (a == b);
    printf("%d", bl);
}