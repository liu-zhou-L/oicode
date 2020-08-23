#include<cstdio>
int a[105];
int f(int n) {
	int ans=0;
	while(n!=0) {
		ans+=(n%10)*(n%10);
		n/=10;
	}
	return ans;
}
int main() {
	int n;
	bool flag=0;
	scanf("%d",&n);
	a[0]=n;
	int i=0;
	if(n!=1) {
		for(i=1;;i++) {
			a[i]=f(a[i-1]);
			for(int j=0;j<i;j++) {
				if(a[j]==a[i]) {
					flag=1;
					break;
				}
			}
	  		//printf("%d\n",a[i]);
			if(flag==1||a[i]==1) break;
		}
	}
	if(a[i]==1) printf("true");
	else printf("flase");
	return 0;
}
