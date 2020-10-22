#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int cnt = 1;
    for (int i = 1; i <= N; i++)
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0)
            cnt++;

    printf("%d\n", cnt);

    return 0;
}