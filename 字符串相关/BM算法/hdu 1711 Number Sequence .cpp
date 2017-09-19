//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1711
//��Ŀ���⣺�ҵڶ��������ڵ�һ�������г��ֵ�λ�ã����û�г������-1
//����˼·��������BM�㷨��Ҳ������KMP�㷨


#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define T_SIZE 1000
#define P_SIZE 1000
const int maxn = 1000005;
#define INF 0x3f3f3f
using namespace std;
int n, m;

int last(int p[], int  c) {
	int  count = 0;
	int pp = m - 1;
	while (pp >= 0) {
		if (p[pp] == c)
			return m - count - 1;
		pp--;
		count++;
	}
	return -1;
}

int BM_index(int T[], int p[]) {
	int i = m - 1, j = m - 1;
	while (i <= n - 1) {
		if (T[i] == p[j])
			if (j == 0)
				return i;
			else i--, j--;
		else {
			i = i + m - min(j, 1 + last(p, T[i]));
			j = m - 1;
		}
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	int T[maxn], p[maxn];
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)scanf("%d", &T[i]);
		for (int i = 0; i < m; i++)scanf("%d", &p[i]);
		if (BM_index(T, p) == -1)
			cout << "-1" << endl;
		else
			cout << BM_index(T, p) + 1 << endl;
	}
	return 0;
}
