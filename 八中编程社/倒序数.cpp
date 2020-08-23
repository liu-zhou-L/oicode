#include<cstdio>
void dwrite(int i) {
	if(i < 10) {
		printf("%d",i);
		return;
	}
	printf("%d", i % 10);
	dwrite(i / 10);
	return;
}
int main() {
	int a;
	scanf("%d", &a);
	dwrite(a);
	return 0;
}

