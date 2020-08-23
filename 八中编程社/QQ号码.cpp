#include<cstdio>
int main() {
	int n,a[105],index;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&index);
	printf("%d",a[index]);
	return 0;
} 
