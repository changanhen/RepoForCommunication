#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define e 1230
int main() {
  double duration;
  clock_t start, finish;
  start = clock();
  FILE *fp;
  fp = fopen("prime.txt", "w");
  fprintf(fp, "2\n3\n5\n7\n");

  int a[e] = {2, 3, 5};
  int i = 3, n, k, b, m;
  for (n = 7; i < e; n += 2) {
    for (k = 1; a[k] * a[k] <= n; k++) {
      m = 1;
      if (n % a[k])
        continue;
      else {
        m = 0;
        break;
      }
    }
    if (m == 1) {
      a[i] = n;
      fprintf(fp, "%d\n", n);
      i++;
    }
  }
  for (; a[e - 1] * a[e - 1] > n; n += 2) {
    for (k = 1; a[k] * a[k] <= n && k < e; k++) {
      m = 1;
      if (n % a[k])
        continue;
      else {
        m = 0;
        break;
      }
    }
    if (m == 1) {
      fprintf(fp, "%d\n", n);
    }
  }
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  fprintf(fp, "%f seconds\n", duration);
  printf("%f", duration);
  return duration;
}