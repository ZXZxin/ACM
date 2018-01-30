//题目链接：http://poj.org/problem?id=1961
//题目大意：给定一个字符串，问这个字符串的所有前缀中，有哪些前缀可以由某个串重复k次组成，并且这个k最大是多少。这个k需要大于1
//解题思路: 可是说这个题就是 poj 2406 的稍微改动一下 ，那个就是要你算整个字符串可以最大可以由某个字串重复k 次组成，算法都是一样的


#include <iostream>
#include <string.h>
#include <stdio.h>

const int maxn = 1000005;
using namespace std;

int nexts[maxn];
char s[maxn];
int n;

void getNext(char *s,int *nexts) {
	int len = strlen(s);
	int j = 0,k = -1;
	nexts[0] = -1;
	while (j < len) {
		if (k == -1 || s[j] == s[k]) {
			j++, k++;
			nexts[j] = k;
		}
		else {
			k = nexts[k];
		}
	}
}

int main() {
	int kase = 0;
	while (scanf("%d", &n) != EOF && n != 0) {
		scanf("%s", s);
		printf("Test case #%d\n", ++kase);
		getNext(s, nexts);
		for (int i = 2; i <= n; i++) {  // k  必须大于 1 也就是长度必须 >= 2  
			if (nexts[i] != 0 && i % (i - nexts[i]) == 0)printf("%d %d\n", i, i/(i - nexts[i]));  //注意nexts[i] != 0
		}
		printf("\n");
	}
	return 0;
}