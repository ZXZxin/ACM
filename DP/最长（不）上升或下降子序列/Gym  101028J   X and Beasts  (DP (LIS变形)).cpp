//��Ŀ���ӣ�https://vjudge.net/contest/199922#problem/J
//��Ŀ���⣺�����ڸ�����һ�����У�ÿ������һ��Ȩֵ�����Ȩֵ������������2�ĸ���������һ����������Դ�ǰ����ѡ��һЩȨֵ
           //��Ҫ�����������Ҫ��ǰ��Ĵ���������������ѡȡ������Ȩֵ֮��
//����˼·��DP�⣬�е������������е�N*N�㷨�ҹ�



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
				dp[i] = max(dp[i],dp[j] + w[i]);   ///���������������Ϊdp[j]+1
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
			dp[i] = w[i];   //���������������dp����ȫ��Ϊ1
		}
		cout<<lis()<<endl;
	}
	return 0;
}
