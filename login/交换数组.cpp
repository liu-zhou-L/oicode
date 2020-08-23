#include<cstdio>
#include<cstring>
int main()
{
	char a[101],b[101],c[101];
	gets(a);
	gets(b);
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);
	puts(a);
	puts(b);
}
