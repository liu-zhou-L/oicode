#include<cstdio>
int a[25][25],b[25][25];
int main()
{
	int mx,my,bx,by,x,y;
	scanf("%d%d%d%d",&by,&bx,&my,&mx);
	a[my][mx]=1;
	for(int i=-2;i<=2;i+=1)
	{
		for(int j=-2;j<=2;j+=1)
		{
			if(i!=j&&i!=-j&&i!=0&&j!=0)
			{
				a[my+i][mx+j]=1;
			}
		}
	}
	b[1][1]=1; 
	for(int y=1;y<=by;y+=1)
	{ 
		for(int x=2;x<=bx;x+=1)
		{
			if(a[y][x]==1)
			{
				b[y][x]=0;
			}
			else if(y==1||x==1)
			{
				b[y][x]=1;
			}
			else
			{
				b[y][x]=b[y-1][x]+b[y][x-1];
			}
		}
	}
	for(int i=1;i<=15;i+=1)
	{
		for(int j=1;j<=15;j+=1) 
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	//printf("%d",b[by][bx]);
	return 0;		
}
