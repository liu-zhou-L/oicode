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
string n; //�����ַ���n
int s;
main()
{
	cin>>n>>s;
	int len=n.size(); //Ҳ������n.length()��ȡ�ַ���n�ĳ���
	while(s--)
		for(int i=0;i<len;i++) //ö��
			if(n[i]>n[i+1]||i==len-1) //ɾ�������ĵ�һ���ݼ����еĵ�һ������(�������ַ���Ϊ�ǵݼ����У���ɾȥĩβ������)
			{
				n.erase(i,1); //�ѵ�ǰ�ַ����ַ�����ɾ��
				break; //����ʡ�ԣ������ַ������ɾ�ַ�
			}
	while(n[0]=='0'&&n[1]) //ȥ��ǰ׺0�������ٱ���1������
		n.erase(0,1); //ɾȥ��ǰ�ַ�����ͷ��'0'
	cout<<n; //����ַ���
}
*/
