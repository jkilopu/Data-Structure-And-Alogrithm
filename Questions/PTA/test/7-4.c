#include <stdio.h>
int main(void)
{
    char ch;
    int count = 0, i;

    do
    {
        ch = getchar();
        if(ch == '6')
            count++;
        else
        {
            if(count > 3 && count <= 9){
                putchar('9');
                putchar(ch);
            }
            else if(count > 9){
                putchar('2');
                putchar('7');
                putchar(ch);
            }
            else{
                for (i = 0; i < count;i++)
                    putchar('6');
                putchar(ch);
            }
            count = 0;
        }
    } while (ch != '\n');

    return 0;
}