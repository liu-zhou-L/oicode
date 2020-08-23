/*#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int intlen(int i) {
	int ans=0;
	while(i) {
		i/=10;
		ans++;
	}
	return ans;
}
struct nums{
 	int n;
	int len;
}a[25];
bool cmp(nums i,nums j) {
	if(i.len<j.len) {
		if(int(pow(10,j.len-i.len))*i.n==j.n) {
			return i.len<j.len;
		}
		return int(pow(10,j.len-i.len))*i.n>j.n;
	}
	else {
		if(i.n==int(pow(10,i.len-j.len))*j.n) {
			return i.len<j.len;
		}
		return i.n>int(pow(10,i.len-j.len))*j.n;
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i].n);
		a[i].len=intlen(a[i].n);
	}
	sort(a+1,a+1+n,cmp);
	bool flag=1;
	for(int i=1;i<=n;i++) {
		if(a[i].n!=0||i==n) flag=0;
		if(flag==0) printf("%d",a[i].n);
	}
	return 0;
}*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct nums{
	int n[15];
	int len;
	bool flag0;
}a[25];
/*bool cmp(nums i,nums j) {
	int len=i.len>j.len?i.len:j.len;
	for(int k=1;k<=len;k++) {
		if(j.n[k]!=i.n[k]) return j.n[k]<i.n[k];
	}
	return i.len<j.len;
}*/
bool cmp(nums i,nums j) {
	int len=i.len+j.len;
	int s1[35],s2[35];
 	for(int k=1;k<=i.len;k++) {
		s1[k]=s2[j.len+k]=i.n[k];
	}
	for(int k=1;k<=j.len;k++) {
		s2[k]=s1[i.len+k]=j.n[k];
	}
	for(int k=1;k<=len;k++) {
		if(s2[k]!=s1[k]) return s2[k]<s1[k];
	}
}
int main() {
	int n;
	char q[15];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",q);
		for(int j=0;j<strlen(q);j++) {
			a[i].n[j+1]=q[j]-'0';
			if(q[j]-'0'!=0) a[i].flag0=1;
		}
		a[i].len=strlen(q);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) {
		if(a[i].flag0==1||i==n) {
			for(int j=1;j<=a[i].len;j++) printf("%d",a[i].n[j]);
		}
	}
	return 0;
}
