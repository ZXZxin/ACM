//题目链接：http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1551
//题目大意：找一串字符中是否出现"bkpstor"这段字符
//解题思路：这是第二次做了，回忆一下 BM 算法,顺便把 last找坏字符的函数优化了一下，重新理解了一下

#include <iostream>
#include <string.h>
#include <algorithm>
const int maxn = 1000;
using namespace std;

int last(char *p, char c) { //找到文本串的  "坏字符"  在模式串中的位置
	for (int i = strlen(p) - 1; i >= 0; i--)if (p[i] == c)return i;
	return -1;
}

int BM_index(char *T, char *p) {
	int n = strlen(T);
	int m = strlen(p);
	int i = m - 1, j = m - 1;
	while (i <= n - 1) {
		if (T[i] == p[j])
			if (j == 0)return i;
			else i--, j--;
		else {
			i = i + m - min(j, 1 + last(p, T[i]));//文本的不符合的那个 位置 串移动的步数
			j = m - 1;//模式串的新位置
		}
	}
	return -1;
}

int main() {
	char T[maxn];
	while (cin >> T) {
		int cnt = BM_index(T, "bkpstor");
		if (cnt == -1)cout << "Safe" << endl;
		else cout << "Warning" << endl;
	}
	return 0;
}