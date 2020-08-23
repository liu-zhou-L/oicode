#include<cstdio>
int main()
{
	int day,num=0;
	scanf("%d",&day);
	for(int i=1;day>0;i+=1)
	{
		for(int n=1;n<=i;day-=1,n+=1)
		{
			if(n<=i&&day>0)
			{
				num+=i;
			}
		}
	}
	printf("%d",num);
}
