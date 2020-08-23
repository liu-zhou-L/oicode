#include<cstdio>
int main()
{
	int a,b,c,d=0;
	scanf("%d",&a);
	for(b=1;b<=a;b+=1)
	{
		for(c=1;c<=b;c+=1)
		{
			d+=c;
		}
	}
	printf("%d",d);
}

