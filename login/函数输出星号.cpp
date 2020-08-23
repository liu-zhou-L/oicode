#include<cstdio>
void myprintf(int n)
{
	while(n!=0)
	{
		printf("*");
		n-=1; 
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	myprintf(n);
}
