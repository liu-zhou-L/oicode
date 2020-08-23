#include<cstdio>
int main()
{
	int n,y,b,c,num=0,flag2;
	char x;
	scanf("%d%d",&n,&y);
	bool a[n],flag=0;
	for(int i=1;i<=n;i+=1)
	{
		a[i]=(i+1)%2;
	}
	for(int e=1;e<=y;e+=1)
	{
		num=0;
		scanf("%d %d %c",&b,&c,&x);
		for(int w=b-1;w<=c-1;w+=1)
		{
			num+=a[w];
		}
		if(num%2==0)
		{
			if(x=='e')
			{
				flag=1;
				flag2=e;
				break;
			}
		}
		else
		{
			if(x=='o')
			{
				flag=1;
				flag2=e;
				break;
			}
		}
	}
	if(flag==1)
	{
		printf("%d",flag2);
	}
	else
	{
		printf("n");
	}
}
