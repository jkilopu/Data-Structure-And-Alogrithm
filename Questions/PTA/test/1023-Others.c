//PAT1023V1
#include <stdio.h> 
int main()
{
    int a[10], i, k = 1;
    char c2[50] = {'\0'};
    for (i = 0; i < 10; i++)
        scanf("%d",&a[i]);
    //	for(i = 0; i < 10; i++)
    //		printf("%d ", a[i]);
    //检测第一个非零数
    for(i = 0; i < 10; i++)
		if(i != 0 && a[i] != 0)
			break;
    c2[0] = i + '0';
    a[i] = a[i] - 1;
    for (i = 0; i < 10; i++)
    {
        while(a[i] != 0){
            c2[k++] = i + '0';
            a[i]--;	
		}
	}
    for (i = 0; i < k; i++)
        putchar(c2[i]);

    return 0;
}
