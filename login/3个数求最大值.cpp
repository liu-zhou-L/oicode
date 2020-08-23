#include<cstdio>
int main()
{
	int a[3];
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	if(a[1]<a[2])a[1]=a[2];
	if(a[1]<a[3])a[1]=a[3];
	printf("%d",a[1]);
}
