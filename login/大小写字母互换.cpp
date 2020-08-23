#include<cstdio>
int main()
{
	char a[81];
	int n=1;
	gets(a);
	for(int i=0;a[i]!='\0';i+=1)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]-=32;	
		}
		else if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]+=32;
		}	
	}
	printf("%s",a); 
} 
