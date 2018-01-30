//题目链接：https://vjudge.net/contest/169966#problem/Q
//题目大意: 就是将多叉树转换成括号表示法，每个结点用除了'-',|'，和空格的其他字符表示，每个非叶子结点下面有一个"|",然后下面是一排"-",恰好在子节点的上方
//解题思路：这题主要是考察的前序遍历(DFS),主要是处理 输入问题，然后DFS即可

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

const int maxn = 200 + 10;
using namespace std;
char s[maxn][maxn];
int n;

void DFS(int r, int c) {
	printf("%c(", s[r][c]);
	if (r + 1 < n && s[r + 1][c] == '|') {
		int i = c;
		while (s[r + 2][i - 1] == '-'&& i - 1 >= 0)i--;  //找到"-"的最左边的那个点
		while (s[r + 2][i] == '-' && s[r + 3][i] != '\0') {  
			if (!isspace(s[r + 3][i]))DFS(r + 3, i);
			i++;//递归每一个孩子
		}
	}
	printf(")");  //回溯的时候记得输出 ) 
}

int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	getchar();  //读取数字后  要读取字符或者字符串  一定要清空一下
	while (T--) {
		n = 0;
		while (gets(s[n])) {
			if (s[n++][0] == '#') { n--; break; }
		}
		printf("(");//两端用括号阔起
		if (n) {
			for (int i = 0; i < strlen(s[0]); i++) {
				if (!isspace(s[0][i])) { DFS(0, i); break; }  //只有一个根 
			}
		}
		printf(")\n"); //两端用括号阔起
	}
	return 0;
}

//刘汝佳的做法(主要是  输入的不同  )熟悉fgets(char *s,int n,sstream)的用法
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

const int maxn = 200 + 10;
using namespace std;
char s[maxn][maxn];
int n;

void DFS(int r, int c) {
	printf("%c(", s[r][c]);
	if (r + 1 < n && s[r + 1][c] == '|') {
		int i = c;
		while (s[r + 2][i - 1] == '-'&& i - 1 >= 0)i--;
		while (s[r + 2][i] == '-' && s[r + 3][i] != '\0') {
			if (!isspace(s[r + 3][i]))DFS(r + 3, i);
			i++;
		}
	}
	printf(")");
}

int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	fgets(s[0], maxn, stdin);  //从文件stream中读取maxn-1个字符/一行（若一行不满maxn-1个），s接收字符串//博客:http://blog.csdn.net/jackin2/article/details/5573771
	sscanf(s[0], "%d", &T);
	while (T--) {
		n = 0;
		for (;;) {
			fgets(s[n], maxn, stdin);
			if (s[n][0] == '#')break;
			n++;
		}
		printf("(");
		if (n) {
			for (int i = 0; i < strlen(s[0]); i++) {
				if (!isspace(s[0][i])) { DFS(0, i); break; }
			}
		}
		printf(")\n");
	}
	return 0;
}
/*
数据:
2
    A
    |
--------
B  C   D
   |   |
 ----- -
 E   F G
#
e
|
----
f g
#
*/