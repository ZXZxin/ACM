//题目链接：http://acm.nyist.net/JudgeOnline/problem.php?pid=16
//题目大意：有n个矩形，每个矩形可以用a,b来描述，表示长和宽。
          //矩形X(a,b)可以嵌套在矩形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。
	      //例如（1,5）可以嵌套在（6,2）内，但不能嵌套在（3,4）中。
	     //你的任务是选出尽可能多的矩形排成一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。
//解题思路：看成DAG上的DP，如果矩形X可以嵌套在矩形Y里面，就从X到Y连一条有向边，求DAG的最长路径，
           //而dp[i]=max(dp[j]+1)//一步只能走到它相邻的点


#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#pragma  warning(disable:4996)
const int maxn = 1003;
using namespace std;

struct node {
	int a, b;
}m[maxn];

int map[maxn][maxn];
int dp[maxn];
int n;

int solve(int i) {
	int &ans = dp[i];
	if (ans > 0)return ans;
	ans = 1;
	for (int j = 1; j <= n; j++) {
		if(map[i][j])
		ans = max(ans,solve(j) + 1);
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int  T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a >> m[i].b;
		}
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((m[i].a < m[j].a&&m[i].b < m[j].b) || (m[i].b < m[j].a&&m[i].a < m[j].b))
					map[i][j] = 1;
			}
		}
		memset(dp, 0, sizeof(dp));
		int max_=-1;
		for (int i = 1; i <= n; i++) {
			if (solve(i) > max_)max_ = solve(i);
		}
		cout << max_ << endl;
	}
	return 0;
}