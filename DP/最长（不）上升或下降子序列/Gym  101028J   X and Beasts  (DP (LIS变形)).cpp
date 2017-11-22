//题目链接：https://vjudge.net/contest/199922#problem/J
//题目大意：就是在给定的一组数中，每个数有一个权值，这个权值是它能整除的2的个数，求这一组数中你可以从前往后选择一些权值
           //但要求输入的数据要比前面的大，求你在这组数中选取的最大的权值之和
//解题思路：DP题，有点和最长上升子序列的N*N算法挂钩



#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

const int maxn = 100 + 10;
int dp[maxn],a[maxn],w[maxn];
int n;
int lis(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				dp[i] = max(dp[i],dp[j] + w[i]);   ///在最长上升子序列中为dp[j]+1
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)ans = max(dp[i],ans);
	return ans;
}


int main(){
	int T,temp;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i = 0; i < n; i++)cin>>a[i];
		for(int i = 0; i < n; i++){
			int temp = a[i];
			int sum = 0;
			while(temp % 2 == 0){
				sum++;
				temp /= 2;
			}
			w[i] = sum;
			dp[i] = w[i];   //在最长上升子序列中dp数组全部为1
		}
		cout<<lis()<<endl;
	}
	return 0;
}
