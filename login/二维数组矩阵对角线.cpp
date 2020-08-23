#include<cstdio>
int main()
{
	int a[8][8],y,x;
	bool flag=0;
	for(y=1;y<=6;y+=1)
		for(x=1;x<=6;x+=1)
			scanf("%d",&a[y][x]);
	for(y=1,x=1;y<=6,x<=6;y+=1,x+=1)
		a[y][x]+=10;
	for(y=1,x=6;y<=6,x>0;y+=1,x-=1)
		a[y][x]+=10;
	for(y=1;y<=6;y+=1)
	{
		for(x=1;x<=6;x+=1)
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
