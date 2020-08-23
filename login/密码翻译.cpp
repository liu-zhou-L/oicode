#include<cstdio>
int main()
{
	char a[81];
	int n=1;
	gets(a);
	for(int i=0;a[i]!='\0';i+=1)
	{
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
		{
			if (a[i]=='z'||a[i]=='Z')
			{
				a[i]-=25;
			}
			else
			{
				a[i]+=1;
			}	
		}	
	}
	printf("%s",a); 
} 
