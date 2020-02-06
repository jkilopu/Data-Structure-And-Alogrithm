#include<stdio.h>
int main()
{
	int a[1000000]={ 0 };
	int N,K,M; 
	int i,n,m,t=0;//t是标志符，一举两用，在是否输出空格和是否找到太帅的人做标记 
	scanf("%d",&N); 
	while(N--)
	{
		scanf("%d",&K);
		for(i=1;i<=K;i++)
		{
			scanf("%d",&n);
			if(K!=1)
			{
				a[n]=1;//此人不帅
			}	 
		}
	}
	scanf("%d",&M);	
	while(M--)
	{
		scanf("%d",&m);
		if(a[m]==0)
		{
			if(t!=0) printf(" ");//按输出格式的 
			printf("%05d",m);// '%05d',输出占五位，不足者用0补位  
			a[m]=1;//输出后，做标记，避免重复查询 
			t++; 
		}		
	}
	if(t==0) printf("No one is handsome");
	return 0;
} 
