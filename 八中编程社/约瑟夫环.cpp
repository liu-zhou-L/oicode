#include<cstdio>
int main() {
	bool a[1005]={};
	int n,m;
	scanf("%d%d",&n,&m);
	int i=1,j=1,w=n;
	while(w>=1) {
		if(a[i]==0) {
			if(j==m) {
				printf("%d ",i);
				w--;
				j=0;
				a[i]=1;
			}
			j+=1;
		}
		if(i==n) i=0;
		i+=1;
	}
	return 0;
}
