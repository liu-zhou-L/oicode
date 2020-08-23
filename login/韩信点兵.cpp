#include<cstdio>
int main()
{
	int a,b,c,d,e=0;
	scanf("%d%d%d",&a,&b,&c);
	for(d=1;d<=100;d+=1)
	{
		if(d%3==a&&d%5==b&&d%7==c)
		{
			printf("%d",d);
			e=1;
			break;
		}
	}
	if(e==0)
	{
		printf("no answer");
	}
}
