#include<cstdio>
int main()
{
	int n,a[15][15],b[15][15];
	bool flag=0;
	scanf("%d",&n);
	for(int y=1;y<=n;y+=1)
		for(int x=1;x<=n;x+=1)
			scanf("%d",&a[y][x]);
	for(int x=1;x<=n;x+=1)
		for(int y=1;y<=n;y+=1)
			b[y][x]=a[x][y];
	for(int y=1;y<=n;y+=1)
	{
		for(int x=1;x<=n;x+=1)
		{
			if(flag==0)
			{
				printf("%d",b[y][x]);
				flag=1;
			}
			else
			{
				printf(" %d",b[y][x]);
			}
		}
		flag=0;
		printf("\n");
	}
}
