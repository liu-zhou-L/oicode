#include<cstdio>
int main()
{
	char a[60],b[60];
	bool flag=0;
	gets(a);
	gets(b);
	for(int i=0;a[i]!='\0';i+=1)
	{
		if(a[i]!='\0')
		{
			printf("%c",a[i]);
		}
		if(b[i]!='\0')
		{
			printf("%c",b[i]);
		}
	}
}
