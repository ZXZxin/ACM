//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=2546
//��Ŀ���⣺������
//����˼·���е�˼ά��01��������ΪҪʹ��ʣ��Ǯ���٣�����Ҫ�������������������ֻ�������˵�ǰn-1������dp
           //����Ҫ���5��Ǯ��������f[n-5],Ȼ���ȥ����


#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
const int maxn=1000001+5;
using namespace std;

int w[maxn];
int f[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int n,V;
    while(cin>>n&&n){
      for(int i=0;i<n;i++)cin>>w[i];
      sort(w,w+n);
      cin>>V;
      if(V<5){cout<<V<<endl;continue;}
      memset(f,0,sizeof(f));
	  for(int i=0;i<n-1;i++)
		for(int v=V;v>=w[i];v--)
			f[v] = max(f[v],f[v-w[i]]+w[i]);
      cout<<V-f[V-5]-w[n-1]<<endl;
    }
    return 0;
}
