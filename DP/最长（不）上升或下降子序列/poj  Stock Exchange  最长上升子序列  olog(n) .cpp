//题目链接：http://poj.org/problem?id=3903
//题目大意：就是求最长递增子序列，只不过数据比较大，只能用olog(n)算法
//解题思路：olog(n)算法


#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

const int maxn = 100000+5;
const int INF = 100000000;
int a[maxn];
int dp[maxn];
int b[maxn];//b数组就是n^2算法中的dp数组即表示以a[i]结尾的最大上升子序列
int pos[maxn];//记录路径的数组
int fa[maxn];
vector<int>res;

int main(void)
{
    //freopen("in.txt","r",stdin);
    int n,x;
    while(cin>>n){
    res.clear();
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0;i<=n;i++) dp[i] = INF;
    int ans = 0;
    pos[0] = -1;
    for(int i=0;i<n;i++){
        int lis = lower_bound(dp,dp+n,a[i])-dp;
        dp[lis] = a[i];
        pos[lis] = i;//记录路径
        fa[i] = lis?pos[lis-1]:-1;
        //b[i] = lis;
        ans = max(ans,lis);
	}
	int i;
	for(i = pos[ans];~fa[i];i=fa[i])res.push_back(a[i]);
	res.push_back(a[i]);
	for(int i =res.size()-1;i>=0;i--)cout<<res[i]<<" ";cout<<endl;
	cout<<ans+1<<endl;//注意数组下标，最好是从1开始
	//for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    //cout<<endl;
    }
}
