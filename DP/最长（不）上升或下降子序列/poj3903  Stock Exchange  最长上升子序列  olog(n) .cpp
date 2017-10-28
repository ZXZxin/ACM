//��Ŀ���ӣ�http://poj.org/problem?id=3903
//��Ŀ���⣺����������������У�ֻ�������ݱȽϴ�ֻ����olog(n)�㷨
//����˼·��olog(n)�㷨


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
int b[maxn];//b�������n^2�㷨�е�dp���鼴��ʾ��a[i]��β���������������
int pos[maxn];//��¼·��������
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
        pos[lis] = i;//��¼·��
        fa[i] = lis?pos[lis-1]:-1;
        //b[i] = lis;
        ans = max(ans,lis);
	}
	int i;
	for(i = pos[ans];~fa[i];i=fa[i])res.push_back(a[i]);
	res.push_back(a[i]);
	for(int i =res.size()-1;i>=0;i--)cout<<res[i]<<" ";cout<<endl;
	cout<<ans+1<<endl;//ע�������±꣬����Ǵ�1��ʼ
	//for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    //cout<<endl;
    }
}
