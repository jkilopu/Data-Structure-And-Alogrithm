#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    char pw[21], input[100];
    int N;
    
    scanf("%s%d", pw, &N);
    getchar();
    do
    {
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';
        if (strcmp(pw, input) != 0 && strcmp(input, "#") != 0)
        {
            printf("Wrong password: %s\n", input);
            N--;
        }
        else
            break;
        
    }
    while (N > 0 && strcmp(input, "#") != 0);
    
    if (N == 0)
        printf("Account locked\n");
    else if (strcmp(input, "#") != 0)
        printf("Welcome in\n");
    
    return 0;
}