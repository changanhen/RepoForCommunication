#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define max_a 100000000 //994203961 + 1
#define max_p 50000000
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
    start = clock();
    for (int j = 4; j < max_a; j++)
    {
        for (int k = 2; k < sqrt(j); k++)
        {
            if (j % k == 0)
                break;  /* 检测到合数直接break */
            if (k + 1 > sqrt(j))
            {
                fprintf(fp, "%d\n", j);
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