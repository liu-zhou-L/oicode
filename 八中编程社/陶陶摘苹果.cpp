#include<cstdio>
int main() {
	int a[10],max,sum=0;
	for(int i=0;i<10;i+=1) scanf("%d",&a[i]);
	scanf("%d",&max);
	for(int i=0;i<10;i+=1)
		if(a[i]<=max+30) sum++;
	printf("%d",sum);
	return 0;
}
