//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2546
//题目大意：中文题
//解题思路：有点思维的01背包，因为要使得剩的钱最少，所以要把最贵的留在最后买，所以只对排序了的前n-1件进行dp
           //其中要抽出5块钱，所以是f[n-5],然后减去最贵的


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
