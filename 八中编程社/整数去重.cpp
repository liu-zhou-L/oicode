#include<cstdio>
bool a[105];
int main() {
	int n,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		scanf("%d",&b);
		if(a[b]==0) {
			printf("%d ",b);
			a[b]=1;
		}
	}
	return 0;
}
