/* https://codeforces.com/contest/1187/problem/A */
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int n,s,t;
}egg;
int main(int argc,char *argv[])
{
	int N, i;
	egg* p;
	scanf("%d", &N);
	p = (egg*)malloc(N * sizeof(egg));
	
	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d", &(p + i)->n, &(p + i)->s, &(p + i)->t);
	}
	for (i = 0; i < N; i++)
	{
		if ((p + i)->n - (p + i)->s > (p + i)->n - (p + i)->t)
			printf("%d\n", (p + i)->n - (p + i)->s + 1);
		else printf("%d\n", (p + i)->n - (p + i)->t + 1);
	}
	free(p);

	return 0;
}
/*总结
1.主要运用数学,算出只有stick和toy的egg有多少
2.C语言的指针操作挺繁琐的...*/