#include<cstdio>
#include<iostream>
using namespace std;
int main() {
	int s,len=0;
	string a;
	cin>>a;
	scanf("%d",&s);
	len=a.size();
	for(int i=1;i<=s;i++) {
		for(int j=0;j<len;j++) {
			if(a[j]>a[j+1]||j==len-1) {
				a.erase(j,1);
				break;
			}
		}
	}
	while(a[0]=='0'&&a[1]) a.erase(0,1);
	cout<<a;
	return 0;
}
/*#include<iostream>
using namespace std;
string n; //定义字符串n
int s;
main()
{
	cin>>n>>s;
	int len=n.size(); //也可以用n.length()来取字符串n的长度
	while(s--)
		for(int i=0;i<len;i++) //枚举
			if(n[i]>n[i+1]||i==len-1) //删除遇到的第一个递减序列的第一个数字(若整个字符串为非递减序列，则删去末尾的数字)
			{
				n.erase(i,1); //把当前字符从字符串中删除
				break; //不可省略，否则字符串会多删字符
			}
	while(n[0]=='0'&&n[1]) //去掉前缀0，并至少保留1个数字
		n.erase(0,1); //删去当前字符串开头的'0'
	cout<<n; //输出字符串
}
*/
