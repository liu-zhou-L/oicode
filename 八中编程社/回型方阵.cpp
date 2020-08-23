#include<cstdio>
int main() {
	int n,sum=1;
	scanf("%d",&n);
	if(n%2==0) {
		for(int i=1;i<=n/2;i++) {
			for(int j=1;j<=n;j++) {
				printf("%d ",sum);
				if(j<=i-1) sum++;
				else if(j>=n-i+1) sum--;
			}
			sum=1;
			printf("\n");
		}
		for(int i=n/2;i>=1;i--) {
			for(int j=1;j<=n;j++) {
				printf("%d ",sum);
				if(j<=i-1) sum++;
				else if(j>n-i) sum--;
			}
			sum=1;
			printf("\n");
		}
	}
	else {
		for(int i=1;i<=n/2+1;i++) {
			for(int j=1;j<=n;j++) {
				printf("%d ",sum);
				if(j<=i-1) sum++;
				else if(j>=n-i+1) sum--;
			}
			sum=1;
			printf("\n");
		}
		for(int i=n/2;i>=1;i--) {
			for(int j=1;j<=n;j++) {
				printf("%d ",sum);
				if(j<=i-1) sum++;
				else if(j>n-i) sum--;
			}
			sum=1;
			printf("\n");
		}
	}
	return 0;
}
