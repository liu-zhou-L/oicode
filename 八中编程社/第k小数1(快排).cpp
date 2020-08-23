/*#include<cstdio>
#include<algorithm>
using namespace std;
struct a{
	int a,num;
}b[100005]; 
void qsort(int l,int r) {
	int i=l,j=r,t=b[l].a;
	if(l>r) return;
	while(i!=j) {
		while(b[j].a>=t&&i<j) j--;
		while(b[i].a<=t&&i<j) i++;
		if(i<j) {
			swap(b[i].a,b[j].a);
			swap(b[i].num,b[j].num);
		}
	}
	swap(b[l].a,b[i].a);
	swap(b[l].num,b[i].num);
	qsort(l,i-1);
	qsort(i+1,r);
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i+=1) {
		b[i].num=i;
		scanf("%d",&b[i].a);
	}
	qsort(1,n);
	printf("%d",b[k].num);
	return 0;
}
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
void qsort(int l,int r) {
	int i=l,j=r,t=b[l];
	if(l>r) return;
	while(i!=j) {
		while(b[j]>=t&&i<j) j--;
		while(b[i]<=t&&i<j) i++;
		if(i<j) {
			swap(b[i],b[j]);
		}
	}
	swap(b[l],b[i]);
	qsort(l,i-1);
	qsort(i+1,r);
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i+=1) {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	qsort(1,n);
	for(int i=1;i<=n;i+=1) {
		if(a[i]==b[k]) {
			printf("%d",i);
			break;
		}
	}
	return 0;
}
