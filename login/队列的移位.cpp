#include <cstdio>
int main()
{
	int a[1001],b,c;
	scanf("%d",&b);
	for(c=1;c<=b;c+=1)
	{
		scanf("%d",&a[c]);
	}
	for(c=1;c<=b;c+=1)
	{
		printf("%d",a[c]);
	if(c!=b)
		{
			printf(" ");
		}
	}
	printf("\n");
	for(c=2;c<=b;c+=1)
	{
		printf("%d ",a[c]);
	}
	printf("%d",a[1]);
	return 0;
}
