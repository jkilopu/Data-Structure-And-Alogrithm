/* ASCII相关知识 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ascii[128] = {0};
    int ch, i_max, i;
    while((ch = getchar()) != '\n')
        if (isalpha(ch))
            ascii[tolower(ch)]++;

    for(i = 0, i_max = 0; i < 128; i++)
        if(ascii[i] > ascii[i_max] && isalpha(i))
            i_max = i;

    printf("%c %d\n", tolower(i_max), ascii[i_max]);

    return 0;
}