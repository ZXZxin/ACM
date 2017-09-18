//题目链接：http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1551
//题目大意：找一串字符中是否出现"bkpstor"这段字符
//解题思路：BM算法（两种解法）

//（2）
#include <iostream>
#include <string.h>
#include <algorithm>
#define T_SIZE 1000
#define P_SIZE 1000
const int maxn = 1000;
#define INF 0x3f3f3f
using namespace std;

int last(char *p, char c) {
	int length = strlen(p), count = 0;
	char *pp = p + length - 1;
	while (pp >= p) {
		if (*pp == c)
			return length - count - 1;
		pp--;
		count++;
	}
	return -1;
}

int BM_index(char *T, char *p) {
	int n = strlen(T);
	int m = strlen(p);
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
int sum(char *T, char *P, int s) {
	//输出文本串中包含模式串的数量
	int e = BM_index(T + s, P);
	return e == -1 ? 0 : 1 + sum(T, P, s + e + 1);
}

int main() {
	char T[maxn];
	while (cin>>T) {
		int cnt = sum(T, "bkpstor", 0);
		if (cnt == 0)cout << "Safe" << endl;
		else cout << "Warning" << endl;
		//cout << cnt << endl;
	}
	return 0;
}


//（2）
#include <stdio.h>
#include <string.h>
int BM_index(char t[], char s[])    //返回第一次匹配的位置
{
	int n = strlen(t);    //计算长度
	int m = strlen(s);
	//BM匹配
	int i, j;
	for (i = m - 1; i >= n - 1; i--)
		if (s[i] == t[n - 1]) {
			for (j = 2; j <= n; j++)
				if (t[n - j] != s[i - j + 1])
					break;
			if (j > n) break;
		}
	if (i >= n - 1) return i - n + 1;
	return -1;
}
int main()
{
	char t[20] = "bkpstor", s[110];
	while (scanf("%s", s) != EOF) {
		if (BM_index(t, s) == -1)
			printf("Safe\n");
		else
			printf("Warning\n");
	}
	return 0;
}