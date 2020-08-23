#include<cstdio>
bool flag[10005];
int main() {
	int l,m,h,n,sum=0;
	scanf("%d %d",&l,&m);
	for(int i=1;i<=m;i+=1) {
		scanf("%d %d",&h,&n);
		for(int i=h;i<=n;i+=1) flag[i]=1;
	}
	for(int i=0;i<=l;i+=1)
		if(flag[i]==0) sum+=1;
	printf("%d\n",sum);
	return 0;
} 
