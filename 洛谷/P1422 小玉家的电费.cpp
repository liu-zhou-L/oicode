#include<cstdio>
int main()
{
	int a;
	double num=0;
	scanf("%d",&a);
	if(a<=150)
	{
		num+=a*0.4463;
	}
	else if(a>150&&a<=400)
	{
		num+=150*0.4463+(a-150)*0.4663;
	}
	else
	{
		num+=150*0.4463+250*0.4663+(a-400)*0.5663;
	}
	printf("%.1lf",num);
}
