#include<cstdio>
int main() {
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i+=1) scanf("%d",&a[i]);
	int b,sum=0; 
	scanf("%d",&b);
	for(int i=0;i<n;i+=1)
		if(a[i]!=b) sum+=a[i];
	printf("%d",sum);
}
