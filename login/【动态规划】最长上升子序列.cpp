#include<cstdio>
int a[5005],b[5005];
int max(int i,int j) {
	return i>j?i:j;
}
int main() {
	int n,len=-999999999;
	scanf("%d",&n);
	for(int i=0;i<n;i+=1)
		scanf("%d",&a[i]);
	b[0]=1;
	for(int i=1;i<n;i+=1)
		for(int j=0;j<i;j+=1)
			if(a[i]<a[j]) {
				b[j]=max(b[i]+1,b[j]);
				if(len<b[j]) len=b[j];
			}
	printf("%d",len);
	return 0;
}
