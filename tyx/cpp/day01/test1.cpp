#include <cstring>
long long int fibonacci(int _Xx)
{
    static long long int save[1000];
    static bool first = true;
    if (first)
        first = false, memset(save, -1, sizeof(save));
    if (save[_Xx] != -1)
        return save[_Xx];
    if (_Xx <= 2)
        return 1;
    return save[_Xx] = fibonacci(_Xx - 1) + fibonacci(_Xx - 2);
}