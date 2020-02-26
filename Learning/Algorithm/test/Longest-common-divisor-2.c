#include <stdio.h>
#include <string.h>
#define MAXELEMENTS 50
#define MAX(a, b) a > b ? a : b
int Lcs_R(char a[], int n, char b[], int m);
int Lcs(char a[], int n, char b[], int m);
int Lcs(char a[], int n, char b[], int m);
int main(void)
{
    char a[] = "isolation fwvamoeosafuei uiwANC  Ueiavneuiazv", b[] = "algorithm aDywatbWbv IAwnhVwwsrgivhfiesznev";
    int len_a = strlen(a), len_b = strlen(b);
    printf("The longest common divisor is: %d\n", Lcs(a, len_a, b, len_b));

    return 0;
}
int Lcs_R(char a[], int n, char b[], int m) // 不能用栈，因为必须永久保存两个字符串的信息
{
    if (n == 0 || m == 0)
        return 0;
    if (a[n - 1] == b[m - 1])
        return Lcs(a, n - 1, b, m - 1) + 1;
    else
        return MAX(Lcs(a, n, b, m - 1), Lcs(a, n - 1, b, m));
}
int Lcs(char a[], int n, char b[], int m) // 就像画表一样
{
    int i, j, record[n][m];
    // 初始化
    for (i = 0; i < n || i < m; i++)
    {
        if (i < n)
            record[i][0] = 0;
        if (i < m)
            record[0][i] = 0;
    }
    // 填表
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            // 元素比较
            if (a[i] == b[j])
                record[i][j] = record[i - 1][j - 1] + 1;
            else
                record[i][j] = MAX(record[i - 1][j], record[i][j - 1]);
        }
    }
    return record[i - 1][j - 1];
}