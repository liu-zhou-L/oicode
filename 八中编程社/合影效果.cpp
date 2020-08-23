#include<cstdio>
//#include<cstring>
#include<algorithm>
using namespace std;
const char male[]="male";
double a[60],b[60];
bool setstrcmp(const char str1[],const char str2[]) {
	int i=0;
	while(str1[i]!='\0'||str2[i]!='\0') {
		if(str1[i]!=str2[i]) return 0;
		i++;
	}
	return 1;
}
bool cmp(double i,double j) {
	return i>j;
}
int main() {
	int n,m=0,wm=0;
	char nn[10];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",nn);
		if(setstrcmp(nn,male)) {
			scanf("%lf",&a[++m]);
		}
		else {
			scanf("%lf",&b[++wm]);
		}
	}
	sort(a+1,a+1+m);
	sort(b+1,b+1+wm,cmp);
	for(int i=1;i<=m;i++) printf("%.2lf ",a[i]);
	for(int i=1;i<=wm;i++) printf("%.2lf ",b[i]);
	return 0;
}

