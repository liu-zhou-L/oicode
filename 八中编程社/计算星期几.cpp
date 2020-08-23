#include<cstdio>
#include<cstdio>
int main() {
	long long a,b;
	scanf("%lld%lld",&a,&b);
	for(int i=2;i<=b;i+=1) a=a*a%7;
	switch(a) {
		case 0: printf("Sunday"); break;
		case 1: printf("Monday"); break;
		case 2: printf("Tuesday"); break;
		case 3: printf("Wednesday"); break;
		case 4: printf("Thursday"); break;
		case 5: printf("Friday"); break;
		case 6: printf("Saturday"); break;
	}
	return 0;
} 
