//��Ŀ���ӣ�http://poj.org/problem?id=1961
//��Ŀ���⣺����һ���ַ�����������ַ���������ǰ׺�У�����Щǰ׺������ĳ�����ظ�k����ɣ��������k����Ƕ��١����k��Ҫ����1
//����˼·: ����˵�������� poj 2406 ����΢�Ķ�һ�� ���Ǹ�����Ҫ���������ַ���������������ĳ���ִ��ظ�k ����ɣ��㷨����һ����


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
		for (int i = 2; i <= n; i++) {  // k  ������� 1 Ҳ���ǳ��ȱ��� >= 2  
			if (nexts[i] != 0 && i % (i - nexts[i]) == 0)printf("%d %d\n", i, i/(i - nexts[i]));  //ע��nexts[i] != 0
		}
		printf("\n");
	}
	return 0;
}