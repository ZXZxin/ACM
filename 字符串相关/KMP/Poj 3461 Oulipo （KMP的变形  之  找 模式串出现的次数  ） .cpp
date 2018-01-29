//��Ŀ���ӣ�http://poj.org/problem?id=3461
//��Ŀ����: ���Ǹ��������ַ��� a �� b ��Ҫ���� a �� b ���ֵĴ���
//����˼·�������Ҫ�� �޸� KMP��������ƥ��ɹ��ǲ�������ѭ��������ֱ�Ӱ����һ���ַ�ʧ������ȥ����ģʽ�����Ի�ȡ��һ�����ܳ��ֵ�ƥ�䡣
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 1000000 + 10;
using namespace std;
int nexts[10000 + 10];
char a[maxn], b[10000 + 10];

void getNext(char *p, int next[]) {  //�Ż������next����ķ��� 
	int len = strlen(p);
	next[0] = -1;   //next �����е� ��󳤶�ֵ(ǰ��׺�Ĺ�����󳤶�) �ĵ�һ�� ��ֵΪ  -1  
	int k = -1, j = 0;
	while (j < len ) {
		if (k == -1 || p[j] == p[k]) { //p[k]��ʾǰ׺ p[j] ��ʾ��׺
			k++; j++;
			if (p[j] != p[k])next[j] = k;
			else next[j] = next[k];   //��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]
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
		if (j == pLen) { // ƥ��ɹ�ʱ��������ѭ�������� ����  ƥ��
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