#include<cstdio>
int main()
{
	int N,a[210][210]={0},x,y,flag=0,num;
	scanf("%d",&N);
	for(num=1,x=N,y=1;num<=(2*N-1)*(2*N-1);num+=1)
	{
		a[y][x]=num;
		if(a[y-1][x+1]!=0||(x==2*N-1&&y==1))
		{
			y+=1;
		}
		else if(y==1)
		{
			y=2*N-1;
			x+=1;
		}
		else if(x==2*N-1)
		{
			y-=1;
			x=1;
		}
		else if(y==2*N-1)
		{
			y-=1;
			x+=1;
		}
		else
		{
			y-=1;
			x+=1;
		}
	}
	a[y][x]=num;
	for(y=1;y<=2*N-1;y+=1)
	{
		for(x=1;x<=2*N-1;x+=1)
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
