//��Ŀ���ӣ�https://vjudge.net/contest/185947#problem/A
//��Ŀ���⣺��������n����վ�����Ϊ1-n����M1�������ҿ���M2��������
          //��ʱ��0������Ҫ����Tʱ�̻����վn��һ�������Ҫ��ȴ���ʱ�����
//����˼·��DP��⣬dp[i][j]��ʾ��j��վ��1-n�����ٻ���Ҫ�ȴ��೤ʱ��߽�������dp[T][n]=0
          //����dp[T][i]=INF,��ÿ����վ�����־���
          //��1������һ���ӣ�2����������ҵĳ���3���������ĳ� 

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
const int maxn = 200;
#pragma warning(disable:4996)
using namespace std;

int dp[maxn][maxn];
bool has_train[maxn][maxn][2];
int t[maxn];

int main() {
	//freopen("in.txt", "r", stdin);
	int n, T, M1, M2, tt;
	int kase = 0;
	while (cin >> n >> T && n) {
		for (int i = 1; i <= n - 1; i++)dp[T][i] = INF;
		dp[T][n] = 0;
		memset(has_train, false, sizeof(has_train));
		for (int i = 1; i <= n - 1; i++) {
			cin >> t[i];
		}
		cin >> M1;
		for (int i = 0; i < M1; i++) {
			cin >> tt;
			for (int j = 1; j <= n - 1; j++) {
				if(tt<=T)has_train[tt][j][0] = true;
				tt += t[j];
			}
		}
		cin >> M2;
		for (int i = 0; i < M2; i++) {
			cin >> tt;
			for (int j = n-1; j >= 1; j--) {
				if(tt<=T)has_train[tt][j+1][1] = true;
				tt += t[j];
			}
		}
		for (int i = T - 1; i >= 0; i--) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = dp[i + 1][j] + 1;//�ȴ�һ����
				if (j < n && has_train[i][j][0] && i + t[j] <= T) {
					dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);//״̬ת�Ʒ��̣������ߣ�
				}
				if (j > 1 && has_train[i][j][1] && i + t[j - 1] <= T) {
					dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);//������
				}
			}
		}
		cout << "Case Number " << ++kase << ": ";
		if (dp[0][1] >= INF)cout << "impossible" << endl;
		else cout << dp[0][1] << endl;
	}
	return 0;
}