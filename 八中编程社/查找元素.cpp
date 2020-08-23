#include<cstdio>
int main() {
	int n,c;
	double a[10005],b;
	scanf("%d",&n);
	for(int i=0;i<n;i+=1) scanf("%lf",&a[i]);
	scanf("%lf",&b);
	for(int i=0;i<n;i+=1) {
		if(a[i]==b) {
			c=i+1;
			break;
		}
	}
	printf("%d",c);
	return 0;
} 
