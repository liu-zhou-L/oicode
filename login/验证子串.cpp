#include<cstdio>
#include<cstring>
int main()
{
	char f[201],z[201],c[201];
	bool flag=0;
	scanf("%s %s",f,z);
	if(strlen(f)>strlen(z))
	{
		strcpy(c,f);
		strcpy(f,z);
		strcpy(z,c);
	}
	for(int i=0;z[i]!='\0';i+=1)
	{
		flag=1;
		for(int n=0;f[n]!='\0';n+=1)
		{
			if(z[i+n]!=f[n])
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("%s",f);
			printf(" is substring of ");
			printf("%s",z);
			return 0;
		}
	}
	printf("No substring");
}
