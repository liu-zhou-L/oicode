#include<cstdio>
int main() {
	int n,sum=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1) {
		for(int j=1;j<=n;j+=1) {
			if(j>=i) {
				printf("%2d ",sum);
				sum+=1;	
			}
			else printf("   ");
			
		} 
		printf("\n");
	} 
	return 0;
}
