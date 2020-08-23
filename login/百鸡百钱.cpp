#include<cstdio>
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=0;i<=y;i++)
	{
		for(int j=0;j<=y;j++)
		{
			int t=y-i-j;
			if(t<0||t%3!=0)continue;
			if(t/3+i*5+j*3==x)
			{
				printf("%d %d %d\n",i,j,t);
				return 0;
			} 
		}

	}
	printf("NO SOLUTION\n");
	return 0;
 } 
