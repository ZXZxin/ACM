//��Ŀ���ӣ�http://poj.org/problem?id=2406
//��Ŀ���⣺���������ִ����������
//����˼·��KMP�е�get_next(),����get_nextval()����next�����Ӧ�á�next[len]�����һ���ַ����Ĳ��������������ͬ�ַ�������ô�������len-next[len]
           //..�����������len�ֽܷ��x�����ִ��������������͵õ�ans�ˡ������ֽܷ⡣ֻ���������Լ���ɴ�������Ϊ1��


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