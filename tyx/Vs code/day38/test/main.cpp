#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define e 29
int main() {
  double duration;
  clock_t start, finish;
  start=clock();
  FILE*fp;
  fp=fopen("prime.txt","w");
  fprintf(fp,"2\n3\n5\n7\n");

  long a[e]={2,3,5};//质数数列
  long b[e]={4,9,25};//质数的平方，减少重复运算
  int i =3,k,m;//几个计数变量
  long n;//遍历奇数
  for (n=7;i<e;n+=2)//遍历所有数直到第e个质数 
  {
    for (k=1;b[k]<=n;k++)//将n除以所有质数 
	{
      m=1;//bool计数变量
      if(n%a[k])//判断是否为质数
        continue;
      else 
	  {
        m=0;
        break;
      }
    }
    if (m==1) 
	{
      a[i]=n;//录入质数数组
	  b[i]=n*n;
      fprintf(fp,"%d\n",n);//录入文件
      i++;
    }
  }
  //第一次大循环，算出基础质数。（前e个）
  
  for (;b[e-1]>n;n+=2)//第二次循环，得到的质数直接录入文件 
  {
    for (k=1;b[k]<=n&&k<e;k++) 
	{
      m=1;
      if (n%a[k])
        continue;
      else 
	  {
        m=0;
        break;
      }
    }
    if (m==1) 
	{
      fprintf(fp,"%d\n",n);
    }
  }
  finish=clock();
  duration=(double)(finish-start) / CLOCKS_PER_SEC;
  fprintf(fp,"%f seconds\n",duration);
  printf("%f\n",duration);
  return 0;
}
