#include<cstdio>
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d %d",((c-a)*60+(d-b))/60,((c-a)*60+(d-b))%60);
	return 0;
}
