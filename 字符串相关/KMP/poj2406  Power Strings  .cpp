//题目链接：http://poj.org/problem?id=2406
//题目大意：求连续的字串的最大数量
//解题思路：KMP中的get_next(),或者get_nextval()，对next数组的应用。next[len]是最后一个字符跳的步长，如果他有相同字符串，则该串长度是len-next[len]
           //..如果整个长度len能分解成x个这种串（能整除），就得到ans了。否则不能分解。只能是由他自己组成串，长度为1。


#include <iostream>
#include <string.h>
#include <stdio.h>
const int maxn = 1000005;
using namespace std;
int nexts[maxn];
int m;
char p[maxn];

void getNext() {
	int k = -1;
	int j = 0;
    m = strlen(p);
	nexts[0] = -1;
	while (j < m) {
		if (k == -1 || p[j] == p[k]) {
			j++, k++;
			nexts[j] = k;
		}
		else {
			k = nexts[k];
		}
	}
}

int main() {
	while (gets(p)&&p[0]!='.') {
		getNext();
		if (m % (m - nexts[m]) != 0)cout << 1 << endl;
		else cout << m / (m - nexts[m]) << endl;
	}
	return 0;
}