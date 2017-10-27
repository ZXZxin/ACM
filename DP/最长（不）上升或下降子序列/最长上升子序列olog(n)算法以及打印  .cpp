//最长递增子序列olog(n)算法以及打印算法

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int mx = int(1e5) + 5;

int a[mx], dp[mx], pos[mx], fa[mx];
vector<int> ans;

int get_lis(int n)
{
	memset(dp, 0x3f, sizeof(dp));
	pos[0] = -1;
	int i, lpos;
	for (i = 0; i < n; ++i)
	{
		dp[lpos = (lower_bound(dp, dp + n, a[i]) - dp)] = a[i];
		pos[lpos] = i; /// *靠后打印
		fa[i] = (lpos ? pos[lpos - 1] : -1);
	}
	n = lower_bound(dp, dp + n, inf) - dp;
	for (i = pos[n - 1];~fa[i]; i = fa[i]) ans.push_back(a[i]);
	ans.push_back(a[i]); /// 最后逆序打印ans即可
	return n;
}

int main(){
    freopen("in.txt","r",stdin);
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){cin>>a[i];}
        int sum = get_lis(n);
        cout<<"最长单调递增子序列长度为:"<<sum<<endl;
        for(int i = ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
        cout<<endl;
    }
	return 0;
}


/*
测试数据：6
1 5 8 3 6 7
*/
