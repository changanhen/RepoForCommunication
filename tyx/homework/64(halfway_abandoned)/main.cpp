#include <stdio.h>
#include <string.h>
typedef struct letter
{
    char ltr;
    int ctr;
} chs;
int main()
{
    char string[82];
    scanf("%s", string);
    chs characters[25];
    for (int i = 0; i < 26; i++)
    {
        characters[i].ctr = 0;
        characters[i].ltr = i + 'A';
    }
    for (int i = 0; i < strlen(string); i++)
    {
        switch (string[i])
        {
        case ('a'):
            characters[0].ctr++;
            break;
        case ('b'):
            characters[1].ctr++;
            break;
        case ('c'):
            characters[2].ctr++;
            break;
        case ('d'):
            characters[3].ctr++;
            break;
        case ('e'):
            characters[4].ctr++;
            break;
        case ('f'):
            characters[5].ctr++;
            break;
        case ('g'):
            characters[6].ctr++;
            break;
        case ('h'):
            characters[7].ctr++;
            break;
        case ('i'):
            characters[8].ctr++;
            break;
        case ('j'):
            characters[9].ctr++;
            break;
        case ('k'):
            characters[10].ctr++;
            break;
        case ('l'):
            characters[11].ctr++;
            break;
        case ('m'):
            characters[12].ctr++;
            break;
        case ('n'):
            characters[13].ctr++;
            break;
        case ('o'):
            characters[14].ctr++;
            break;
        case ('p'):
            characters[15].ctr++;
            break;
        case ('q'):
            characters[16].ctr++;
            break;
        case ('r'):
            characters[17].ctr++;
            break;
        case ('s'):
            characters[18].ctr++;
            break;
        case ('t'):
            characters[19].ctr++;
            break;
        case ('u'):
            characters[20].ctr++;
            break;
        case ('v'):
            characters[21].ctr++;
            break;
        case ('w'):
            characters[22].ctr++;
            break;
        case ('x'):
            characters[23].ctr++;
            break;
        case ('y'):
            characters[24].ctr++;
            break;
        case ('z'):
            characters[25].ctr++;
            break;
        }
    }
}
