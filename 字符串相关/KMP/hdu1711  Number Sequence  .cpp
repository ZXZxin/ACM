//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1711
//��Ŀ���⣺�ҵڶ��������ڵ�һ�������г��ֵ�λ�ã���������ڣ����-1
//����˼·��ģ��KMP��ע����Ż�


#include <iostream>
#include <string.h>
#include <stdio.h>
const int maxn = 1000005;
using namespace std;
int s[maxn], p[maxn];
int n, m;
int nexts[maxn];

void getNext() {//�Ż����kmp
	int k = -1;
	int j = 0;
	nexts[0] = -1;
	while (j < m-1) {
		if (k == -1 || p[j] == p[k]) {
			j++, k++;
			if (p[j] != p[k]) {
				nexts[j] = k;
			}
			else {
				nexts[j] = nexts[k];
			}
		}
		else {
			k = nexts[k];
		}
	}
}

int Kmpserch() {
	int i = 0;
	int j = 0;
	getNext();
	while (i < n&&j<m) {
		if (j == -1 || s[i] == p[j]) {
			i++, j++;
		}
		else {
			j = nexts[j];
		}
		if (j == m)return i - j + 1;//��һ����Ϊ��Ŀ���Ǵ�1��ʼ//ע���ж���������ѭ������
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)scanf("%d", &s[i]);
		for (int j = 0; j < m; j++)scanf("%d", &p[j]);
		cout << Kmpserch() << endl;
	}
	return 0;
}