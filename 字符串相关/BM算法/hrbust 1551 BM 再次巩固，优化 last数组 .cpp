//��Ŀ���ӣ�http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1551
//��Ŀ���⣺��һ���ַ����Ƿ����"bkpstor"����ַ�
//����˼·�����ǵڶ������ˣ�����һ�� BM �㷨,˳��� last�һ��ַ��ĺ����Ż���һ�£����������һ��

#include <iostream>
#include <string.h>
#include <algorithm>
const int maxn = 1000;
using namespace std;

int last(char *p, char c) { //�ҵ��ı�����  "���ַ�"  ��ģʽ���е�λ��
	for (int i = strlen(p) - 1; i >= 0; i--)if (p[i] == c)return i;
	return -1;
}

int BM_index(char *T, char *p) {
	int n = strlen(T);
	int m = strlen(p);
	int i = m - 1, j = m - 1;
	while (i <= n - 1) {
		if (T[i] == p[j])
			if (j == 0)return i;
			else i--, j--;
		else {
			i = i + m - min(j, 1 + last(p, T[i]));//�ı��Ĳ����ϵ��Ǹ� λ�� ���ƶ��Ĳ���
			j = m - 1;//ģʽ������λ��
		}
	}
	return -1;
}

int main() {
	char T[maxn];
	while (cin >> T) {
		int cnt = BM_index(T, "bkpstor");
		if (cnt == -1)cout << "Safe" << endl;
		else cout << "Warning" << endl;
	}
	return 0;
}