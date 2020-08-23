#include<cstdio>
int main()
{
	int i,j,a[15][15],b;
	bool flag=0;
	scanf("%d,%d",&i,&j);
	for(int y=1;y<=i;y+=1)
		for(int x=1;x<=j;x+=1)
			scanf("%d",&a[y][x]); 
	for(int y=1;y<=i;y+=1)
		for(int x=1;x<=j;x+=1)
		{
			scanf("%d",&b);
			a[y][x]+=b;
		}
	for(int y=1;y<=i;y+=1)
	{
		for(int x=1;x<=j;x+=1)
		{
			if(flag==0)
			{
				printf("%d",a[y][x]);
				flag=1;
			}
			else
			{
				printf(" %d",a[y][x]);
			}
		}
		flag=0;
		printf("\n");
	}
}
