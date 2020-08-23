#include<cstdio>
int main()
{
	char a[31],b,c;
	scanf("%s %c %c",a,&b,&c);
	for(int i=0;a[i]!='\0';i+=1)
	{
		if(a[i]==b)
		{
			a[i]=c;
		}
	}
	puts(a);
} 
