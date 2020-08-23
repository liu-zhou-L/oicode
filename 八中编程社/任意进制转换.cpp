#include<cstdio>
#include<cmath>
#include<cstring>
int main() {
	int num=0, sum = 1,n,m,len;
	char s_1[20],a;
	int de=0;
	while((a=getchar())!='<') {
		s_1[de++]=a;
	};
	scanf("%d>%d",&n,&m);
	for(int i=de-1;i>=0;i--) {
		num+=(s_1[i]-48) * pow(n,de-i-1);
	}
	while(1) {
		if(sum <= num && sum * m > num) break;
		sum *= m;
	}
	for(int i=0;i<de;i++) printf("%c",s_1[i]);
	printf("<%d>=",n);
	while(num) {
		printf("%d", num / sum);
		num %= sum;
		sum /= m;
	}
	while(sum >= 1) {
		printf("0");
		sum /= m;
	}
	printf("<%d>",m);
	/*for(int i=0;i<de;i++) printf("%c",s_1[i]);
	printf("\n%d\n%d\n%d",de,n,m);*/
	return 0;
}

