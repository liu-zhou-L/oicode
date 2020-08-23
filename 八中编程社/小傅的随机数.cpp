#include<cstdio>
bool flag[1001];
int main() {
	int n,a,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		scanf("%d",&a);
		flag[a]=1;
	}
	for(int i=1;i<=1000;i+=1)
		if(flag[i]==1) sum+=1;
	printf("%d\n",sum);
	for(int i=1;i<=1000;i+=1)
		if(flag[i]==1) printf("%d ",i);
	return 0;
} 
