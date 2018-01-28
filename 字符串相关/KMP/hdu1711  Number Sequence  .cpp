//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1711
//��Ŀ���⣺�ҵڶ��������ڵ�һ�������г��ֵ�λ�ã���������ڣ����-1
//����˼·��ģ��KMP��ע����Ż�
//��Ҫ��֪ʶ��:
        //(1) ʧ��ʱ��ģʽ�� p �����ƶ���λ��Ϊ��ʧ���ַ�����λ�� - ʧ���ַ���Ӧ�� next ֵ
        //(2) ʧ��ʱ��ģʽ�� p �����ƶ���λ��Ϊ����ƥ���ַ��� - ʧ���ַ�����һλ�ַ�����Ӧ����󳤶�ֵ(����ǰ׺��׺�Ĺ���Ԫ�ص���󳤶ȱ�)
		/*(3)  next ������� :  ��p[k] == p[j]���� next[j + 1 ] = next [j] + 1 = k + 1��
         ��p[k ] �� p[j]�������ʱ p[ next[k] ] == p[j ]���� next[ j + 1 ] = next[k] + 1��
		 ��������ݹ�ǰ׺���� k = next[k]�������ظ��˹��̡� �൱�����ַ� p[j+1] ֮ǰ�����ڳ���Ϊ k+1 ��ǰ׺"p0 p1, ��, pk-1 pk"����׺��pj-k pj-k+1, ��, pj-1 pj"��ȣ�
		 ��ô�Ƿ���ܴ�����һ��ֵ t+1 < k+1��ʹ�ó��ȸ�С��ǰ׺ ��p0 p1, ��, pt-1 pt�� ���ڳ��ȸ�С�ĺ�׺ ��pj-t pj-t+1, ��, pj-1 pj�� �أ�
		 ������ڣ���ô��� t+1 ���� next[ j+1] ��ֵ�����൱�������Ѿ���õ� next ���飨next [0, ..., k, ..., j]������ P ��ǰ׺�� P ����׺��ƥ�䡣
		*/
#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 1000000 + 10;
using namespace std;
int nexts[10000 + 10];
int n, m;
int a[maxn], b[10000 + 10];

void getNext(int *p,int next[]) {  //�Ż������next����ķ��� 
	int len = m;
	next[0] = -1;   //next �����е� ��󳤶�ֵ(ǰ��׺�Ĺ�����󳤶�) �ĵ�һ�� ��ֵΪ  -1  
	int k = -1,j = 0;
	while (j < len - 1) {
		if (k == -1 || p[j] == p[k]) { //p[k]��ʾǰ׺ p[j] ��ʾ��׺
			k++; j++;
			if(p[j] != p[k])next[j] = k;
			else next[j] = next[k];   //��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]
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