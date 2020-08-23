#include<cstdio>
#include<algorithm>
using namespace std;
int a[105];
int maxArea(int a[],int siz){
	int left=0,right=siz-1;
	int water=min(a[left],a[right])*(right-left);
	while(left<right){
		if(a[left]<a[right]) ++left;
		else --right;
		water=max(water,min(a[left],a[right])*(right-left));
	}
	return water;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	printf("%d",maxArea(a,n));
}
