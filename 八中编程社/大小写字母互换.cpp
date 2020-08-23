#include <cstdio>
int main()
{
	char a;
	while(scanf("%c",&a)!=EOF) {
		if(a>='a'&&a<='z') a-=32;
		else if(a>='A'&&a<='Z') a+=32;
		printf("%c",a);
	}
	return 0;
}
