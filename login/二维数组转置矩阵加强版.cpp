#include<cstdio>
int main()
{
	int n,m,a[15][15];
	bool flag=0;
	scanf("%d%d",&n,&m);
	for(int y=1;y<=n;y+=1)
		for(int x=1;x<=m;x+=1)
			scanf("%d",&a[y][x]);
	for(int y=1;y<=m;y+=1)
	{
		for(int x=1;x<=n;x+=1)
		{
			if(flag==0)
			{
				printf("%d",a[x][y]);
				flag=1;
			}
			else
			{
				printf(" %d",a[x][y]);
			}
		}
		flag=0;
		printf("\n");
	}
}
