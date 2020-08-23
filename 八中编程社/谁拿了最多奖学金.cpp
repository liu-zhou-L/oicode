#include<cstdio>
struct stu{
	char name[30],xg,xs;
	int ans,score1,score2,lw;
};
stu a[105];
int main() {
	int n,index=1,anss=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		scanf("%s %d %d %c %c %d",a[i].name,&a[i].score1,&a[i].score2,&a[i].xg,&a[i].xs,&a[i].lw);
		if(a[i].score1>80&&a[i].lw>=1) a[i].ans+=8000;
		if(a[i].score1>85&&a[i].score2>80) a[i].ans+=4000;
		if(a[i].score1>90) a[i].ans+=2000;
		if(a[i].score1>85&&a[i].xs=='Y') a[i].ans+=1000;
		if(a[i].score2>80&&a[i].xg=='Y') a[i].ans+=850;
		if(a[i].ans>a[index].ans) index=i;
		anss+=a[i].ans;
	}
	printf("%s\n%d\n%d",a[index].name,a[index].ans,anss);
	return 0;
}
