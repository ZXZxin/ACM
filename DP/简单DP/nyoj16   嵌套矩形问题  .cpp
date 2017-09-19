//��Ŀ���ӣ�http://acm.nyist.net/JudgeOnline/problem.php?pid=16
//��Ŀ���⣺��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�
          //����X(a,b)����Ƕ���ھ���Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d���൱����תX90�ȣ���
	      //���磨1,5������Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С�
	     //���������ѡ�������ܶ�ľ����ų�һ�У�ʹ�ó����һ���⣬ÿһ�����ζ�����Ƕ������һ�������ڡ�
//����˼·������DAG�ϵ�DP���������X����Ƕ���ھ���Y���棬�ʹ�X��Y��һ������ߣ���DAG���·����
           //��dp[i]=max(dp[j]+1)//һ��ֻ���ߵ������ڵĵ�


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