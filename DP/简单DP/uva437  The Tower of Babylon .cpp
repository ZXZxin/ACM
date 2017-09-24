//��Ŀ���ӣ�https://vjudge.net/contest/185947#problem/B
//��Ŀ���⣺��n�������壬ÿ�ֶ�����������Ҫ��ѡһЩ������ѳ�һ�������ߵ����ӣ�
          //ʹÿ��������ĵ��泤���ϸ�С�����·���������ĵ��泤��
//����˼·��ֻ�е���ĳ����Ӱ�쵽�������ߣ���˿����ö�Ԫ������ʾ��������DAG��̬�滮��ģ��
          //�������ݿ��ܴܺ������ö�Ԫ�飨dix,k������ʾ�ڼ��������壬��ÿ�������������Ԫ�����򣬺�������ڵ���ţ�


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