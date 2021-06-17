#include <stdio.h>
typedef struct student
{
    char student_number[10];
    char student_name[10];
    int score1;
    int score2;
    int score3;
    int score_all;
} stu;

int main()
{
    void stu_bubble(int n, stu stu_group[]);
    int n;
    scanf("%d", &n);
    stu stu_group[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%d%d%d", stu_group[i].student_number, stu_group[i].student_name, &stu_group[i].score1, &stu_group[i].score2, &stu_group[i].score3);
        stu_group[i].score_all = stu_group[i].score1 + stu_group[i].score2 + stu_group[i].score3;
    }
    stu_bubble(n, stu_group);
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %d %d %d %d\n", stu_group[i].student_number, stu_group[i].student_name, stu_group[i].score1, stu_group[i].score2, stu_group[i].score3, stu_group[i].score_all);
    }
}
void stu_bubble(int n, stu stu_group[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (stu_group[j].score_all > stu_group[j + 1].score_all)
            {
                stu tmp = stu_group[j];
                stu_group[j] = stu_group[j + 1];
                stu_group[j + 1] = tmp;
            }
        }
    }
}