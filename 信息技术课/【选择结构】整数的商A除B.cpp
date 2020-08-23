#include<cstdio>
int main() {
	int a,b;
	scanf("%d %d",&a,&b);
	if(b==0) {
		printf("ERROR");
		return 0;
	}
	printf("%d",a/b);
	return 0;
}
