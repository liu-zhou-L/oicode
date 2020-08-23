#include<cstdio>
int main() {
	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);
	for(int i=1;i<=n;i++) {
		printf("(%d,%d) ",k,i);
	}
	printf("\n");
	for(int i=1;i<=n;i++) {
		printf("(%d,%d) ",i,l);
	}
	printf("\n");
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j+=1) {
			if(j-i==l-k) printf("(%d,%d) ",i,j);
		}
	}
	printf("\n");
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(j+i==l+k) printf("(%d,%d) ",j,i);
		}
	}
	return 0;
}
