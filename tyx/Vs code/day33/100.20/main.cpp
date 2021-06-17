//一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include <stdio.h>
int main()
{
    double height = 100.0, sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum += height;
        height /= 2;
        sum += height;
    }
    sum -= height;
    printf("第十次落地时共经过%lf米，第十次反弹%lf米", sum, height);
}