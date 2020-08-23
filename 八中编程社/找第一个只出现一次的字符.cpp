#include<cstdio>
char a[100005];
int main() {
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++) {
		int flag=1;
		for(int j=0;a[j]!='\0';j++) {
			if(a[j]==a[i]&&j!=i) {
				flag=0;
				break;
			}
		}
		if(flag==1) {
			printf("%c",a[i]);
			break;
		}
		else if(a[i+1]=='\0') {
			printf("no");
		}
	}
	return 0;
}
