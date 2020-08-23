#include<cstdio> 
#include<cstring>
int main()
{
	int i,j,n,c[110][110];
	bool flag=0;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	c[0][0]=1;c[1][0]=1;c[1][1]=1;
	for(i=2;i<n;i+=1)
	{
		c[i][0]=1;
		for(j=1;j<=i;j+=1)
		{
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for(i=0;i<n;i+=1)
	{
		for(j=0;j<=i;j+=1)
		{
			if(flag==0) 
			{
				printf("%d",c[i][j]);
				flag=1;
			}
			else printf(" %d",c[i][j]);
		}
		printf("\n");
		flag=0;
	} 
	return 0;
}
