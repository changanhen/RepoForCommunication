/*设计思路：用bool型数组array来存储所有自然数，质数在array里面的值为1，而合数为2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define max_a 100000000 //994203961 + 1
int main()
{
    double duration;
    clock_t start, finish;
    start = clock();
    FILE *fp;
    fp = fopen("prime.txt", "w");
    fprintf(fp, "2\n3\n5\n7\n");
    //char array[max_a] = { 0 };
    char *array = (char *)malloc(sizeof(char) * max_a);
    int a_Nptr = 2;
    /*int isPrime = 0;                                                //isPrime用来存储0和1，0代表合数，1代表质数*/
    array[2] = 1;
    array[3] = 1;
    array[5] = 1;
    array[7] = 1;
    for (int j = 5; j < max_a; j++)
    {
        if (array[j] == 2)
            continue; /* 对于已排除项，直接continue */
        if (j % 2 == 0)
            continue;
        for (int k = 3; k < sqrt(j); k += 2)
        {
            if (array[k])
            {
                if (j % k == 0)
                    break; /* 检测到合数直接break */
            }
            if (k + 2 >= sqrt(j))
            {
                array[j] = 1; /* 该条程序执行的条件是这个数是质数，因此加入质数组并进行互乘排除 */
                fprintf(fp, "%d\n", j);
                for (; array[a_Nptr] && a_Nptr * j < max_a; a_Nptr++)
                {
                    array[a_Nptr * j] = 2;
                }
            }
        }
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    fprintf(fp, "%f seconds\n", duration);
    printf("%f\n", duration);
    return 0;
}