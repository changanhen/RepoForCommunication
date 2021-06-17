//利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
#include <stdio.h>
int main()
{
    int score;
    printf("请输入分数：");
    scanf("%d", &score);
    printf("成绩为：");
    score >= 60? (score >= 90? printf("A"): printf("B")): printf("C");
}