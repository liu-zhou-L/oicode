#include<cstdio>
int main() {
	char x;
	while((x=getchar())!=EOF) {
		if((x>=65&&x<=90)||(x>=97&&x<=122)) {
			if(x==90||x==122) x-=25;
			else x++;
		}
		printf("%c",x);
	}
	return 0;
}
