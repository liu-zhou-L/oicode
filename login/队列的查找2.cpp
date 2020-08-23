#include<cstdio>
int main()
{
	int n,num[10001],x,flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i+=1){
		scanf("%d",&num[i]);
	}
	scanf("%d",&x);
	for(int i=1;i<=n;i+=1){
		if(num[i]==x){
			flag=1;
			break;
		}
	}
	if(flag==1){
		for(int i=1;i<=n;i+=1){
			if(num[i]!=x&&i!=n){
				printf("%d ",num[i]);
			}
			if(num[i]!=x&&i==n){
				printf("%d\n",num[i]);
			}
		}
	} 
	else{
		for(int i=1;i<=n;i+=1){
			if(i!=n){
				if(num[i]<x&&num[i+1]>x||num[i]>x&&i==1){
					printf("%d ",x);
				}
				printf("%d ",num[i]);
				
			}
			else{
				printf("%d",num[i]);
				if(num[i]<x){
					printf("%d\n",x);
				}
				else{
					printf("\n");
				}
			}
		}
	}
}
