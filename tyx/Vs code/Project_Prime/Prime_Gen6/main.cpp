#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define e 1230
int main()
{
    double duration;
    clock_t start, finish;
    start = clock();
    FILE *fp;
    fp = fopen("prime.txt", "w");
    fprintf(fp, "2\n3\n5\n");
    long prime[e] = {2, 3, 5};        //质数数列
    long prime_square[e] = {4, 9, 25};       //质数的平方，减少重复运算
    int i = 3, k, m = 1, stl = 2; //几个计数变量
    long n;                       //遍历奇数
    for (n = 7; i < e; n += 2)    //遍历所有数直到第e个质数
    {
        for (k = 1; prime_square[k] <= n; k++) //将n除以所有质数
        {
            m = 1;        //bool计数变量
            if (n % prime[k]) //判断是否为质数
                continue;
            else
            {
                m = 0;
                break;
            }
        }
        if (m == 1)
        {
            prime[i] = n; //录入质数数组
            prime_square[i] = n * n;
            fprintf(fp, "%d\n", n); //录入文件
            i++;
        }
    }
    //第一次大循环，算出基础质数。（前e个）
    for (; prime_square[e - 1] > n; n += stl)  //第二次循环，得到的质数直接录入文件
    {                               //优化2：将n+=2改成用stl控制的一次+2一次+4
        stl ^= 6;                   //废语句 这里出现了一个迷惑的情况，加了无效语句比不加无效语句速度更快
        for (k = 2; prime_square[k] <= n; k++) /*优化1：删掉了&&，提升了1.5s速度*/
        {                           //优化3：从5开始试除，因为6n-1和6n+1不可能被2，3整除
            m = 1;
            if (n % prime[k])
                continue;
            else
            {
                m = 0;
                break;
            }
        }
        if (m == 1)
        {
            fprintf(fp, "%d\n", n);
        }
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    fprintf(fp, "%f seconds\n", duration);
    printf("%f\n", duration);
    fclose(fp);
    return 0;
}
