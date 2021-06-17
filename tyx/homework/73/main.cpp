#include <stdio.h>
typedef struct person
{
    char ID_num[16];
    int sith;
    int sitm;
    int sits;
    int soth;
    int sotm;
    int sots;
    int sis;
    int sos;
} loginer;
int main()
{
    void it_bbl(int n, loginer lgr[]);
    void ot_bbl(int n, loginer lgr[]);
    int m;
    scanf("%d", &m);
    loginer lgr[100];
    for (int i = 0; i < m; i++)
    {
        scanf("%s%d:%d:%d%d:%d:%d", lgr[i].ID_num, &lgr[i].sith, &lgr[i].sitm, &lgr[i].sits, &lgr[i].soth, &lgr[i].sotm, &lgr[i].sots);
        lgr[i].sis = 3600 * lgr[i].sith + 60 * lgr[i].sitm + lgr[i].sits;
        lgr[i].sos = 3600 * lgr[i].soth + 60 * lgr[i].sotm + lgr[i].sots;
    }
    it_bbl(m, lgr);
    printf("%s ", lgr[0].ID_num);
    ot_bbl(m, lgr);
    printf("%s", lgr[0].ID_num);
}
void it_bbl(int n, loginer lgr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lgr[j].sis > lgr[j + 1].sis)
            {
                loginer tmp = lgr[j];
                lgr[j] = lgr[j + 1];
                lgr[j + 1] = tmp;
            }
        }
    }
}
void ot_bbl(int n, loginer lgr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lgr[j].sos < lgr[j + 1].sos)
            {
                loginer tmp = lgr[j];
                lgr[j] = lgr[j + 1];
                lgr[j + 1] = tmp;
            }
        }
    }
}