#include<cstdio>
int main() {
	int n,c,a[100005],b;
	scanf("%d",&n);
	for(int i=0;i<n;i+=1) scanf("%d",&a[i]);
	scanf("%d",&b);
	for(int i=0;i<n;i+=1)
		if(i!=b-1) printf("%d ",a[i]);
	return 0;
} 
