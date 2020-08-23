#include<cstdio>
int main()
{
	int a[5][5],b[5],flag=0,c,d;
	for(int x=0;x<=4;x+=1)
	{
		for(int y=0;y<=4;y+=1)
		{
			scanf("%d",&a[x][y]);
		} 
	}
	scanf("%d%d",&d,&c);
	for(int i=0;i<=4;i+=1)
	{
		b[i]=a[d-1][i];
		a[d-1][i]=a[c-1][i];
		a[c-1][i]=b[i];
	} 
	for(int x=0;x<=4;x+=1)
	{
		for(int y=0;y<=4;y+=1)
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
		printf("\n");
		flag=0;
	}
} 
