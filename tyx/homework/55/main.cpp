//用strchr去匹配字符串，特殊情况NotFound写在if后面，然后else后面去检验还有没有下一个匹配到的，匹配到一个删一个。
//（删除方法可以用赋0，类似质数算法）
#include <stdio.h>
#include <string.h>
int main()
{
    char string[101], ch, * ptr, is_or_not = 1;
    scanf("%s %c", string, &ch);
    ptr = strchr(string, ch);
    if (!ptr)
        is_or_not = 0;
    while (ptr)
    {
        while (*ptr)
        {
            *ptr = *(ptr + 1);
            ptr++;
        }
        ptr = strchr(string, ch);
    }
    is_or_not? printf("%s", string): printf("NotFound");
}