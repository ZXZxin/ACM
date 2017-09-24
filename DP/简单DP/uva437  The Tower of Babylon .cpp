//题目链接：https://vjudge.net/contest/185947#problem/B
//题目大意：有n个立方体，每种都有无穷多个，要求选一些立方体堆成一根尽量高的柱子，
          //使每个立方体的底面长宽严格小于它下方的立方体的底面长宽
//解题思路：只有底面的长宽会影响到后续决策，因此可以用二元组来表示，可以用DAG动态规划的模型
          //由于数据可能很大，所以用二元组（dix,k）来表示第几个立方体，对每个立方体的三个元素排序，和其高所在的序号，


#include <iostream>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)
#define maxn 1000
using namespace std;

int n;
int block[maxn][maxn];
int dp[maxn][maxn];

void gett(int *v, int b, int vim) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (i != vim)v[cnt++] = block[b][i];
	}
}

int solve(int i, int j) {
	int &ans = dp[i][j];
	if (ans > 0)return ans;
	ans = 0;
	int v[2],v2[2];
	gett(v, i, j);
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < 3; b++) {
			gett(v2, a, b);
			if (v[0] < v2[0] && v[1] < v2[1])ans = max(ans, solve(a, b));
		}
	}
	ans += block[i][j];
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int kase = 0;
	while (cin >> n&&n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> block[i][j];
			}
			sort(block[i], block[i] + 3);
		}
		memset(dp, -1, sizeof(dp));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				ans = max(ans, solve(i, j));
			}
		}
		cout <<"Case "<<++kase<<": maximum height = "<< ans << endl;
	}
	return 0;
}