#include<cstdio>
int main()
{
	int b=123;
	char a[1001];
	gets(a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]+=32;
		}
	}
	for(int i=97;i<=122;i+=1)
	{
		for(int n=0;a[n]!='\0';n+=1)
		{
			if(a[n]==i)
			{
				printf("%c",i);
			}
		}
	}
}
