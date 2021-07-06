#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define e 1e3
int main() {
    int a, b;
    FILE* fp;
    fp = fopen("random.txt", "w");
    srand((unsigned)time(NULL));
    fprintf(fp, "%d\n", (int)e);
    for (int i = 0; i < e; i++)
    {
        a = rand();
        b = rand();
        fprintf(fp, "%d %d\n", a, b);
    }
    return 0;
}