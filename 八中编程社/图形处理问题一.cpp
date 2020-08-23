#include<cstdio>
#include<cmath>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		for(int j=n-i;j>=1;j-=1) printf(" ");
		for(int j=(i-1)*2+1;j>=1;j-=1) {
			if(j==(i-1)*2+1||j==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=n-1;i>=1;i-=1) {
		for(int j=n-i;j>=1;j-=1) printf(" ");
		for(int j=(i-1)*2+1;j>=1;j-=1) {
			if(j==(i-1)*2+1||j==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}

