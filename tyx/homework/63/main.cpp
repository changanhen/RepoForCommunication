#include <stdio.h>
int main()
{
    char ch, str[100];
    int i = 0, ctr = 0;
    while ((ch = getchar()) != '\n')
        str[i++] = ch;
    for (int j = 0; j < i; j++)
    {
        switch (str[j])
        {
            case '0':
                ctr++? printf(" zero"): printf("zero");
                break;
            case '1':
                ctr++? printf(" one"): printf("one");
                break;
            case '2':
                ctr++? printf(" two"): printf("two");
                break;
            case '3':
                ctr++? printf(" three"): printf("three");
                break;
            case '4':
                ctr++? printf(" four"): printf("four");
                break;
            case '5':
                ctr++? printf(" five"): printf("five");
                break;
            case '6':
                ctr++? printf(" six"): printf("six");
                break;
            case '7':
                ctr++? printf(" seven"): printf("seven");
                break;
            case '8':
                ctr++? printf(" eight"): printf("eight");
                break;
            case '9':
                ctr++? printf(" nine"): printf("nine");
                break;
        }
    }
}