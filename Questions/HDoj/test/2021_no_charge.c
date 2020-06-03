#include <stdio.h>
int main(void)
{
    const int values[] = {100, 50, 10, 5, 2, 1};
    int N;

    while (scanf("%d", &N) && N != 0)
    {
        int salary, n = 0;
        while (N--)
        {
            scanf("%d", &salary);
            for (int i = 0; i < 6 && salary > 0; i++)
            {
                n += salary / values[i];
                salary %= values[i];
            }
        }
        printf("%d\n", n);
    }

    return 0;
}