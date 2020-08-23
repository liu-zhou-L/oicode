#include<cstdio>
int main()
{
	int i,j,b,num=0;
	scanf("%d%d",&i,&j);
	for(int y=0;y<=i-1;y+=1)
	{
		for(int x=0;x<=j-1;x+=1)
		{
			scanf("%d",&b);
			if(y==0||y==i-1||x==0||x==j-1)
			{
				num+=b;
			}
		}
	}
	printf("%d",num);
}
