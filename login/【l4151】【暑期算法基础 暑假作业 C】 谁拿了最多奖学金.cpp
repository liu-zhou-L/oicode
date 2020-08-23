#include<cstdio>
#include<algorithm>
using namespace std;
struct stu
{
	char name[20];
	int faa;
	int cra;
	char sc;
	char siwp;
	int papers;
	int sp = 0;
} a[105];
bool cmp(stu x,stu y)
{
	return x.sp > y.sp;
}
int main()
{
	int n, sps=0, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i += 1)
	{
		scanf("%s %d %d %c %c %d", a[i].name, &a[i].faa, &a[i].cra, &a[i].sc, &a[i].siwp, &a[i].papers);
		if(a[i].faa > 80 && a[i].papers >= 1)	a[i].sp += 8000;
		if(a[i].faa > 85 && a[i].cra > 80)	a[i].sp += 4000;
		if(a[i].faa > 90)	a[i].sp += 2000;
		if(a[i].faa > 85 && a[i].siwp == 'Y')	a[i].sp += 1000;
		if(a[i].cra > 80 && a[i].sc =='Y')	a[i].sp += 850;
		sps += a[i].sp;
	}
	sort(a + 1, a + 1 + n, cmp);
	/*for(i = 1; i <= n ; i += 1)
	{
		printf("%s %d\n", a[i].name, a[i].sp);
	}*/
	printf("%s\n%d\n%d", a[1].name, a[1].sp, sps);
	return 0;
}
