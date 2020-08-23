#include<cstdio>
int main() {
	int n,num=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%5d",num);
			if(num<i) num++;
		}
		num=1;
		printf("\n");
	}
	return 0;
}
