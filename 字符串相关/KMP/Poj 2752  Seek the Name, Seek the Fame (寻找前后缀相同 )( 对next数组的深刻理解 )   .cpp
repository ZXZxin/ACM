//��Ŀ���ӣ�http://poj.org/problem?id=2752
//��Ŀ���⣺���Ǹ���һ���ַ�����Ҫ���� ����ַ����� ���� ǰ׺ ���� ��׺ �����ַ����ĳ���
//����˼·: ������Լ�Ҳû�������������һ���� nexts�����������  

//��������Ƚ�  �������
/*���ڳ���Ϊlen���ַ�������next�Ķ���֪��
A[0]A[1]...A[next[len] - 1] = A[len - next[len]]...A[len - 1]   ��ʱA[0]A[1]...A[next[len] - 1]Ϊһ������������ǰ׺
��A[0]A[1]....A[next[next[len]] - 1] = A[len - next[next[len] - next[next[len]]]...A[next[len] - 1],
��A[0]A[1]....A[next[next[len]] - 1]Ҳ��һ������������ǰ׺
�ʴ�len = > next[len] = > next[next[len]] .... = > ֱ��ĳ��next[]Ϊ0��Ϊ�Ϸ��� ��*/

#include <stdio.h>
#include <iostream>
#include <string.h>

const int maxn = 400000 + 10;
using namespace std;
int nexts[maxn],ans[maxn];;

void getNext(char *p,int *nexts) {
	int len = strlen(p);
	int i = 0,j = -1;
	nexts[0] = -1;
	while (i < len) {
		if (j == -1 || p[i] == p[j]) {
			i++, j++;
			nexts[i] = j;
		}
		else j = nexts[j];
	}
}

int main() {
	char s[maxn];
	while (scanf("%s", s) != EOF) {
		getNext(s, nexts);
		int k = 0;
		int j = nexts[strlen(s)];
		ans[k++] = strlen(s); //�Լ�����϶��� �����  
		while (j > 0) {
			ans[k++] = j;
			j = nexts[j];
		}
		for (int i = k - 1; i > 0; i--)printf("%d ", ans[i]);
		printf("%d\n", ans[0]);
	}
	return 0;
}