#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct patient {
	char id[15];
	int age,num;
}a[50005];
bool cmp(patient i,patient j) {
	if(i.age>=60&&j.age>=60) {
		if(i.age==j.age) return i.num<j.num;
		return i.age>j.age;
	}
	else if(i.age>=60||j.age>=60) return i.age>=60;
	else return i.num<j.num;
}
int main() {
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s%d",a[i].id,&a[i].age);
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) {
		printf("%s %d\n",a[i].id,a[i].age);
	}
	return 0;
}

