//Time Limit Exceeded   60
#include<cstdio>
bool a[1000000005];
int main() {
	int n,m;
	scanf("%d",&n);
	m=1;
	int i=1,j=1,w=n;
	while(w>=1) {
		if(a[i]==0) {
			if(j==m) {
				if(w==1) printf("%d ",i);
				w--;
				a[i]=1;
			}
			if(j==2) j=0;
			j+=1;
		}
		if(i==n) {
			i=0;
			j=1;
		}
		i+=1;
	}
	return 0;
}
/*
#include<cstdio>
struct node{
	node *next;
	node *last;
	int num;
}da;
int sum=1;
node *head=&da;
node *end=&da;
void newnode() {
	end->next=new node;
	sum++;
	end->next->last=end;
	end=end->next;
	end->num=sum;
}
int main() {
	da.last=&da;
	da.next=&da;
	da.num=1;
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		newnode();
	}
	int
	return 0;
}
*/
