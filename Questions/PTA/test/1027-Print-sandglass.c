/*1.功能：程序把给定数目的符号打印成沙漏的形状，并输出未用符号的个数
  2.我的要点：（1）建立要用符号和底部符号个数b的等量关系（2）使用字符串（3）使用循环*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n_sum, n_used, n_unused, i, j;
	int b = 1;
	/*b即bottom，为沙漏底部符号个数，b的值应该可以跟据n_sum
	的值确定（目前不知道怎么确定），这样可以减少运算次数；*/
	char *p, ch;

	scanf("%d %c", &n_sum, &ch);                              //注意空格的作用:无视回车等操作
	n_used = (b * b + 2 * b - 1) / 2;							//等量关系

	//从1开始，算出底部最大符号数（不超过n_sum）
	while ((n_used = (b * b + 2 * b - 1) / 2) <= n_sum)        //注意是<=!!!!
		b += 2;
	b -= 2;														//使b回复到最大值
	p = (char*)malloc(b * sizeof(char));
	n_used = (b * b + 2 * b - 1) / 2;
	n_unused = n_sum - n_used;
	//接下来均是字符串处理
	for (j = 0; j < b; j++)
		p[j] = ch;
	for (i = 0; (b - 1) / 2 - i > 0; i++)
	{
		printf("%s\n", p);
		p[i] = ' ';
		p[b - i - 1] = '\0';    //题目要求后部不能输出空格
	}
	while (i >= 0)
	{
		p[i] = ch;
		p[b - i - 1] = ch;
		printf("%s\n", p);
		i--;
	}
	printf("%d", n_unused);

	return 0;
}
/*出现过的错误:
1.临界状态没搞清（<和<=）
2.字符串处理出错较多
3.不符合题目要求(格式错误：输出了空格)
*/