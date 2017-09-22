//题目链接：https://vjudge.net/contest/185947#problem/A
//题目大意：从左到右有n个车站，编号为1-n，有M1辆车往右开，M2俩车往左开
          //在时刻0出发，要求在T时刻会见车站n的一个间谍，要求等待的时间最短
//解题思路：DP求解，dp[i][j]表示在j车站（1-n）最少还需要等待多长时间边界条件是dp[T][n]=0
          //其他dp[T][i]=INF,在每个车站有三种决策
          //（1）：等一分钟（2）：搭乘往右的车（3）搭乘往左的车 

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
				dp[i][j] = dp[i + 1][j] + 1;//等待一分钟
				if (j < n && has_train[i][j][0] && i + t[j] <= T) {
					dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);//状态转移方程（往右走）
				}
				if (j > 1 && has_train[i][j][1] && i + t[j - 1] <= T) {
					dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);//往左走
				}
			}
		}
		cout << "Case Number " << ++kase << ": ";
		if (dp[0][1] >= INF)cout << "impossible" << endl;
		else cout << dp[0][1] << endl;
	}
	return 0;
}