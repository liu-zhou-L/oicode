#include<cstdio>
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=(n+1)/2;i+=1) {
		for(int j=1;j<=n;j+=1) {
			if(j>=(n+1)/2-(i-2)&&j<=(n+1)/2+(i-2)) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	for(int i=(n+1)/2-1;i>=1;i-=1) {
		for(int j=1;j<=n;j+=1) {
			if(j>=(n+1)/2-(i-2)&&j<=(n+1)/2+(i-2)) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}
