//题目链接：http://poj.org/problem?id=2752
//题目大意：就是给你一个字符串，要你求 这个字符串中 所有 前缀 等于 后缀 的子字符串的长度
//解题思路: 这个题自己也没有想出来，就是一个对 nexts数组的深刻理解  

//这个分析比较  容易理解
/*对于长度为len的字符串，由next的定义知：
A[0]A[1]...A[next[len] - 1] = A[len - next[len]]...A[len - 1]   此时A[0]A[1]...A[next[len] - 1]为一个符合条件的前缀
有A[0]A[1]....A[next[next[len]] - 1] = A[len - next[next[len] - next[next[len]]]...A[next[len] - 1],
故A[0]A[1]....A[next[next[len]] - 1]也是一个符合条件的前缀
故从len = > next[len] = > next[next[len]] .... = > 直到某个next[]为0均为合法答案 。*/

#include <stdio.h>
#include <iostream>
#include <string.h>

const int maxn = 400000 + 10;
using namespace std;
int nexts[maxn],ans[maxn];;

void getNext(char *p,int *nexts) {
	int len = strlen(p);
	int i = 0,j = -1;
	nexts[0] = -1;
	while (i < len) {
		if (j == -1 || p[i] == p[j]) {
			i++, j++;
			nexts[i] = j;
		}
		else j = nexts[j];
	}
}

int main() {
	char s[maxn];
	while (scanf("%s", s) != EOF) {
		getNext(s, nexts);
		int k = 0;
		int j = nexts[strlen(s)];
		ans[k++] = strlen(s); //自己本身肯定是 满足的  
		while (j > 0) {
			ans[k++] = j;
			j = nexts[j];
		}
		for (int i = k - 1; i > 0; i--)printf("%d ", ans[i]);
		printf("%d\n", ans[0]);
	}
	return 0;
}