#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500005],f[500005];
char carn[5];
int w36_10() {
	int ans=0, i=0;
	for(int i = 0; i < 4; i ++) {
		if(carn[4 - i] >= '0' && carn[4 - i] <= '9') {
			ans += (carn[4 - i] - '0') * pow(36, i);
		}
		else {
			ans += (carn[4 - i] - 55) * pow(36, i);
		}	
	}
	return ans;
}
int main() {
	int sum=0,index=1;
	while(scanf("YA%s\n", carn) != EOF) {
		sum ++;
		a[sum] = w36_10();
		//printf("%d\n", a[sum]);
	}
	sort(a + 1, a + 1 + sum);
	for(int i = 1;i <= sum;i ++) {
		f[sum] = a[sum] - a[sum - 1];
		if(abs(f[index]) > abs(f[sum])) index = sum;
	}
	printf("%d\n", f[index]);
	return 0;
}
