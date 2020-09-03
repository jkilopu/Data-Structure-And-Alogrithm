#include <stdio.h>
#include <string.h>

void compress(char *str);
void compress_one_sequence(char *start);
/* 压缩中帮助方法与主方法进行了通信 */
void decompress(char *str);
char *decompress_one_sequence(char *start);

int main(void)
{
    char opt;
    char str[1002];

    scanf("%c", &opt);
    getchar(); // 必要(OJ中不能用fflush())
    fgets(str, 1002, stdin);
    str[strlen(str) - 1] = '\0';
    if (opt == 'C')
        compress(str);
    else if (opt == 'D')
        decompress(str);
    putchar('\n');
    
    return 0;
}

void compress(char *str)
{
    char *seq = str;
    while (*seq != '\0')
    {
        compress_one_sequence(seq);
        char *next_seq = seq;
        while(*next_seq == *seq)
            next_seq++;
        seq = next_seq;
    }
}

void compress_one_sequence(char *start)
{
    char *next = start;
    int cnt = 0;
    while (*next++ == *start)
        cnt++;
    if (cnt != 1)
        printf("%d", cnt);
    putchar(*start);
}

void decompress(char *str)
{
    char *seq = str;
    while(*seq != '\0')
        seq = decompress_one_sequence(seq);
}

char *decompress_one_sequence(char *start)
{
    char *ret = start;
    if (*start <= '9' && *start >= '0')
    {
        int cnt = 0;
        while (*ret <= '9' && *ret >= '0')
        {
            cnt *= 10;
            cnt += *ret - '0';
            ret++;
        }
        while(cnt--)
            putchar(*ret);
    }
    else
        putchar(*start);
    ret++;
    return ret;
}