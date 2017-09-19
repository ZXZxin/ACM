//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2084
//题目大意：求一个数字三角形从上往下走一条路，使得这条路数组和最大
//解题思路：经典的DP题。

//（记忆化搜索）
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#pragma  warning(disable:4996)
const int maxn = 100;
using namespace std;
int dp[maxn][maxn];
int num[maxn][maxn];
int n;

int solve(int i, int j) {
	if (dp[i][j] > 0)return dp[i][j];
	return dp[i][j] = num[i][j] + (i == n-1 ? 0 : max(solve(i + 1, j), solve(i + 1, j + 1)));
}

int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> num[i][j];
			}
		}
		cout << solve(0,0) << endl;
	}
	return 0;
}

//(递推)
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
const int maxn = 100;
using namespace std;
int dp[maxn][maxn];
int num[maxn][maxn];

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> num[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			dp[n - 1][i] = num[n - 1][i];
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				dp[i][j] = num[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
			}
		}
		cout << dp[0][0] << endl;
	}
	return 0;
}
