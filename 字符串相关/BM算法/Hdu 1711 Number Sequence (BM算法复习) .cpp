//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1711
//题目大意：找第二个数组在第一个数组中出现的位置，如果没有出现输出-1
//解题思路：可以用BM算法，也可以用KMP算法，这里又是对last 数组改进一下，顺便加深一下理解

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

#define S_SIZE 1000010
#define P_SIZE 10010
using namespace std;
int n, m;

int last(int p[], int  c) { //找到文本串的  "坏字符"  在模式串中的位置
	for (int i = m - 1; i >= 0; i--)if (p[i] == c)return i;
	return -1;
}

//int last(int p[], int  c) {
//	int  count = 0;
//	int pp = m - 1;
//	while (pp >= 0) {
//		if (p[pp] == c)
//			return m - count - 1;
//		pp--;
//		count++;
//	}
//	return -1;
//}

int BM_index(int s[], int p[]) {
	int i = m - 1, j = m - 1;
	while (i <= n - 1) {
		if (s[i] == p[j])
			if (j == 0)return i;
			else i--, j--;
		else {
			i += m - min(j, last(p, s[i]) + 1);//文本的不符合的那个 位置 串移动的步数
			j = m - 1;  //模式串的新位置
		}
	}
	return -1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int s[S_SIZE], p[P_SIZE];
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)scanf("%d", &s[i]);
		for (int i = 0; i < m; i++)scanf("%d", &p[i]);
		if (BM_index(s, p) == -1)
			cout << "-1" << endl;
		else
			cout << BM_index(s, p) + 1 << endl;
	}
	return 0;
}
