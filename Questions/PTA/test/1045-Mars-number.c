#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    char input[20];
    const char low[][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    const char high[][5] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    scanf("%d", &N);
    getchar();
    while (N--)
    {
        fgets(input, 20, stdin);
        input[strlen(input) - 1] = '\0';
        if (input[0] >= '0' && input[0] <= '9') 
        {
            int n = 0, mHigh, mLow;
            for (int i = 0; input[i] != '\0'; i++) {
                n += input[i] - '0';
                n *= 10;
            }
            n /= 10;
            mHigh = n / 13, mLow = n % 13;
            if (mHigh > 0 && mLow > 0)
                printf("%s %s\n", high[mHigh], low[mLow]);
            else if (mHigh == 0 && mLow > 0)
                printf("%s\n", low[mLow]);
            else
                printf("%s\n", high[mHigh]);
        }
        else
        {
            char sHigh[10], sLow[10];
            char *p = input, *q = sHigh;
            while (*p != ' ' && *p != '\0') 
                *q++ = *p++;
            *q = '\0'; 
            q = sLow;
            if (*p == ' ')
                p++;
            while (*q++ = *p++) 
                ;
            int i, j, n;
            for (i = 0; i < 13; i++)
                if (strcmp(sHigh, high[i]) == 0)
                {
                    n = 13 * i;
                    break;
                }
                else if (strcmp(sHigh, low[i]) == 0)
                {
                    n = i;
                    break;
                }
                
            for (j = 0; j < 13; j++)
                if (strcmp(sLow, low[j]) == 0)
                    break;
            j = (j == 13 ? 0 : j);
            if (sLow[0] != '\0')
                n = 13 * i + j;
            // printf("i = %d, j = %d, sHigh = %s, sLow = %s\n", i, j, sHigh, sLow);
            printf("%d\n", n);
        }
                
    }

    return 0;
}