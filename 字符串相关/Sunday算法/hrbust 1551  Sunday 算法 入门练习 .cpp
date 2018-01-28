//��Ŀ���ӣ�http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1551
//��Ŀ����: ��һ���ַ����Ƿ����"bkpstor"����ַ�
//����˼·: ������Sunday�㷨��һ����
//Sunday�㷨ԭ�� ��ԭ�����  �ַ������Ҷ˶�����ַ�  ����һλû����ƥ�䴮�г�����ֱ�����������ƶ����� = ƥ�䴮���� + 1��
                        //����ͬBM�㷨һ�����ƶ����� = ƥ�䴮�����Ҷ˵ĸ��ַ���ĩβ�ľ��� + 1��
//ѧϰ����:http://blog.csdn.net/zhang0558/article/details/50212183

#include <iostream>
#include <string.h>
#include <algorithm>
const int maxn = 1000;
using namespace std;

int last(char *p, char c) { 
	for (int i = strlen(p) - 1; i >= 0; i--)if (p[i] == c)return i;
	return -1;
}

int Sunday(char *s, char *p) {
	int sLen = strlen(s);
	int pLen = strlen(p);
	int i = 0, j = 0;
	while (i < sLen && j < pLen) {
		if (s[i] == p[j])i++, j++;
		else {
			int index = i + pLen - j;   // �ַ������Ҷ˶�����ַ�
			if (last(p, s[index]) == -1) { i = index + 1; j = 0; }  //  û����ƥ�䴮�г�����ֱ������
			else {
				i = index - last(p, s[index]); j = 0; //����  ���ƶ����� = ƥ�䴮����  �Ҷ�  �ĸ��ַ���ĩβ�ľ��� + 1��
			}
		}
	}
	if (j == pLen)return i - j;
	return -1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	char T[maxn];
	while (cin >> T) {
		int cnt = Sunday(T,"bkpstor");
		if (cnt == -1)cout << "Safe" << endl;
		else cout << "Warning" << endl;
	}
	return 0;
}