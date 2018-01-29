//题目链接：http://poj.org/problem?id=3461
//题目大意: 就是给你两个字符串 a 和 b ，要你求 a 在 b 出现的次数
//解题思路：这个主要是 修改 KMP函数，当匹配成功是不是跳出循环，而是直接按最后一个字符失配的情况去滑动模式串，以获取下一个可能出现的匹配。
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 1000000 + 10;
using namespace std;
int nexts[10000 + 10];
char a[maxn], b[10000 + 10];

void getNext(char *p, int next[]) {  //优化后的求next数组的方法 
	int len = strlen(p);
	next[0] = -1;   //next 数组中的 最大长度值(前后缀的公共最大长度) 的第一个 赋值为  -1  
	int k = -1, j = 0;
	while (j < len ) {
		if (k == -1 || p[j] == p[k]) { //p[k]表示前缀 p[j] 表示后缀
			k++; j++;
			if (p[j] != p[k])next[j] = k;
			else next[j] = next[k];   //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
		}
		else k = next[k];
	}
}

int KMPSerach(char *s, char *p) {
	int sLen = strlen(s);
	int pLen = strlen(p);
	int i = 0, j = 0,count = 0;
	while (i < sLen && j < pLen) {
		if (j == -1 || s[i] == p[j])i++, j++;
		else j = nexts[j];
		if (j == pLen) { // 匹配成功时不是跳出循环，而是 继续  匹配
			count++; j = nexts[j];
		}
	}
	return count;
}
int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s", b, a);
		getNext(b,nexts);
		printf("%d\n", KMPSerach(a,b));
	}
	return 0;
}