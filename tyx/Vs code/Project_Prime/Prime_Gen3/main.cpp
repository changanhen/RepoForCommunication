#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define max_a 1e8
#define max_p 5e7
int push(int data, int a[], int* Nptr)
{
    a[*Nptr] = data;
    *Nptr = *Nptr + 1;
    return 0;
}
int nil(int a[], int* Nptr)
{
    a[*Nptr++] = 0;
    return 0;
}
int main()
{
    double duration;
    clock_t start, finish;
    start = clock();
    FILE* fp;
    fp = fopen("prime.txt", "w");
    fprintf(fp, "2\n3\n");
    int* array = (int*)malloc(sizeof(int) * max_a), * prime = (int*)malloc(sizeof(int) * max_p), /*composite[max_a], */p_Nptr = 0, /*c_Nptr = 0, */a_Nptr = 0;  //建立数组，建立指针指向下一个该进行运算的数据
    int* ptr_p = &p_Nptr, /** ptr_c = &c_Nptr, */* ptr_a = &a_Nptr;    //建立指针，用于向push函数传Nptr
    /*int isPrime = 0;                                                //isPrime用来存储0和1，0代表合数，1代表质数*/
    for (; a_Nptr < max_a; a_Nptr++)
    {
        array[a_Nptr] = a_Nptr; //给array赋值
    }
    for (; p_Nptr < max_p; p_Nptr++)
    {
        prime[p_Nptr] = 0;  /* 给prime赋0 */
    }
    p_Nptr = 0;
    push(2, prime, ptr_p);
    push(3, prime, ptr_p);
    for (int i = 0; i < p_Nptr; i++)
    {
        //push(prime[i] * prime[p_Nptr - 1], composite, ptr_c); /* 2 3 互乘 */
        array[prime[i] * prime[p_Nptr - 1]] = 0;
    }
    for (int j = 5; j < max_a; j++)
    {
        if (array[j] == 0)
            continue;   /* 对于已排除项，直接continue */
        for (int k = 0; prime[k] < sqrt(j); k++)
        {
            if (j % prime[k] == 0)
                break;  /* 检测到合数直接break */
            if (prime[k + 1] > sqrt(j))
            {
                push(j, prime, ptr_p);  /* 该条程序执行的条件是这个数是质数，因此加入质数组并进行互乘排除 */
                fprintf(fp, "%d\n", j);
                for (int l = 0; l < p_Nptr && prime[l] * prime[p_Nptr - 1] < max_a; l++)
                {
                    array[prime[l] * prime[p_Nptr - 1]] = 0;
                }
            }
        }
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    fprintf(fp, "%f seconds\n", duration);
    printf("%f\n", duration);
    free(array);
    free(prime);
    return 0;
}