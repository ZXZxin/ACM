//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1711
//��Ŀ���⣺�ҵڶ��������ڵ�һ�������г��ֵ�λ�ã����û�г������-1
//����˼·��������BM�㷨��Ҳ������KMP�㷨���������Ƕ�last ����Ľ�һ�£�˳�����һ�����

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

#define S_SIZE 1000010
#define P_SIZE 10010
using namespace std;
int n, m;

int last(int p[], int  c) { //�ҵ��ı�����  "���ַ�"  ��ģʽ���е�λ��
	for (int i = m - 1; i >= 0; i--)if (p[i] == c)return i;
	return -1;
}

//int last(int p[], int  c) {
//	int  count = 0;
//	int pp = m - 1;
//	while (pp >= 0) {
//		if (p[pp] == c)
//			return m - count - 1;
//		pp--;
//		count++;
//	}
//	return -1;
//}

int BM_index(int s[], int p[]) {
	int i = m - 1, j = m - 1;
	while (i <= n - 1) {
		if (s[i] == p[j])
			if (j == 0)return i;
			else i--, j--;
		else {
			i += m - min(j, last(p, s[i]) + 1);//�ı��Ĳ����ϵ��Ǹ� λ�� ���ƶ��Ĳ���
			j = m - 1;  //ģʽ������λ��
		}
	}
	return -1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	int s[S_SIZE], p[P_SIZE];
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)scanf("%d", &s[i]);
		for (int i = 0; i < m; i++)scanf("%d", &p[i]);
		if (BM_index(s, p) == -1)
			cout << "-1" << endl;
		else
			cout << BM_index(s, p) + 1 << endl;
	}
	return 0;
}
