//题目链接：http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1551
//题目大意: 找一串字符中是否出现"bkpstor"这段字符
//解题思路: 这里用Sunday算法练一下手
//Sunday算法原理 ：原则：如果  字符串中右端对齐的字符  的下一位没有在匹配串中出现则直接跳过，即移动步长 = 匹配串长度 + 1；
                        //否则，同BM算法一样其移动步长 = 匹配串中最右端的该字符到末尾的距离 + 1。
//学习博客:http://blog.csdn.net/zhang0558/article/details/50212183

#include <iostream>
#include <string.h>
#include <algorithm>
const int maxn = 1000;
using namespace std;

int last(char *p, char c) { 
	for (int i = strlen(p) - 1; i >= 0; i--)if (p[i] == c)return i;
	return -1;
}

int Sunday(char *s, char *p) {
	int sLen = strlen(s);
	int pLen = strlen(p);
	int i = 0, j = 0;
	while (i < sLen && j < pLen) {
		if (s[i] == p[j])i++, j++;
		else {
			int index = i + pLen - j;   // 字符串中右端对齐的字符
			if (last(p, s[index]) == -1) { i = index + 1; j = 0; }  //  没有在匹配串中出现则直接跳过
			else {
				i = index - last(p, s[index]); j = 0; //否则  其移动步长 = 匹配串中最  右端  的该字符到末尾的距离 + 1。
			}
		}
	}
	if (j == pLen)return i - j;
	return -1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	char T[maxn];
	while (cin >> T) {
		int cnt = Sunday(T,"bkpstor");
		if (cnt == -1)cout << "Safe" << endl;
		else cout << "Warning" << endl;
	}
	return 0;
}