//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1711
//题目大意：找第二个数组在第一个数组中出现的位置，如果不存在，输出-1
//解题思路：模板KMP，注意可优化
//重要的知识点:
        //(1) 失配时，模式串 p 向右移动的位数为：失配字符所在位置 - 失配字符对应的 next 值
        //(2) 失配时，模式串 p 向右移动的位数为：已匹配字符数 - 失配字符的上一位字符所对应的最大长度值(各个前缀后缀的公共元素的最大长度表)
		/*(3)  next 数组的求法 :  若p[k] == p[j]，则 next[j + 1 ] = next [j] + 1 = k + 1；
         若p[k ] ≠ p[j]，如果此时 p[ next[k] ] == p[j ]，则 next[ j + 1 ] = next[k] + 1，
		 否则继续递归前缀索引 k = next[k]，而后重复此过程。 相当于在字符 p[j+1] 之前不存在长度为 k+1 的前缀"p0 p1, …, pk-1 pk"跟后缀“pj-k pj-k+1, …, pj-1 pj"相等，
		 那么是否可能存在另一个值 t+1 < k+1，使得长度更小的前缀 “p0 p1, …, pt-1 pt” 等于长度更小的后缀 “pj-t pj-t+1, …, pj-1 pj” 呢？
		 如果存在，那么这个 t+1 便是 next[ j+1] 的值，此相当于利用已经求得的 next 数组（next [0, ..., k, ..., j]）进行 P 串前缀跟 P 串后缀的匹配。
		*/
#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 1000000 + 10;
using namespace std;
int nexts[10000 + 10];
int n, m;
int a[maxn], b[10000 + 10];

void getNext(int *p,int next[]) {  //优化后的求next数组的方法 
	int len = m;
	next[0] = -1;   //next 数组中的 最大长度值(前后缀的公共最大长度) 的第一个 赋值为  -1  
	int k = -1,j = 0;
	while (j < len - 1) {
		if (k == -1 || p[j] == p[k]) { //p[k]表示前缀 p[j] 表示后缀
			k++; j++;
			if(p[j] != p[k])next[j] = k;
			else next[j] = next[k];   //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
		}
		else k = next[k];
	}
}

int KMPSerach(int *s, int *p) {
	int sLen = n;
	int pLen = m;
	int i = 0, j = 0;
	while (i < sLen && j < pLen) {
		if (j == -1 || s[i] == p[j])i++, j++;
		else j = nexts[j];
	}
	if (j == pLen)return i - j;
	else return -1;

}

int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)scanf("%d", &a[i]);
		for(int i = 0; i < m; i++)scanf("%d", &b[i]);
		getNext(b,nexts);
		int ans = KMPSerach(a, b);
		if (ans != -1)printf("%d\n", ans + 1);
		else printf("-1\n");
	}
	return 0;
}