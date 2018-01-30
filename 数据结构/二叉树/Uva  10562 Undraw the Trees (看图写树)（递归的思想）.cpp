//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/Q
//��Ŀ����: ���ǽ������ת�������ű�ʾ����ÿ������ó���'-',|'���Ϳո�������ַ���ʾ��ÿ����Ҷ�ӽ��������һ��"|",Ȼ��������һ��"-",ǡ�����ӽڵ���Ϸ�
//����˼·��������Ҫ�ǿ����ǰ�����(DFS),��Ҫ�Ǵ��� �������⣬Ȼ��DFS����

#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

const int maxn = 200 + 10;
using namespace std;
char s[maxn][maxn];
int n;

void DFS(int r, int c) {
	printf("%c(", s[r][c]);
	if (r + 1 < n && s[r + 1][c] == '|') {
		int i = c;
		while (s[r + 2][i - 1] == '-'&& i - 1 >= 0)i--;  //�ҵ�"-"������ߵ��Ǹ���
		while (s[r + 2][i] == '-' && s[r + 3][i] != '\0') {  
			if (!isspace(s[r + 3][i]))DFS(r + 3, i);
			i++;//�ݹ�ÿһ������
		}
	}
	printf(")");  //���ݵ�ʱ��ǵ���� ) 
}

int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	getchar();  //��ȡ���ֺ�  Ҫ��ȡ�ַ������ַ���  һ��Ҫ���һ��
	while (T--) {
		n = 0;
		while (gets(s[n])) {
			if (s[n++][0] == '#') { n--; break; }
		}
		printf("(");//��������������
		if (n) {
			for (int i = 0; i < strlen(s[0]); i++) {
				if (!isspace(s[0][i])) { DFS(0, i); break; }  //ֻ��һ���� 
			}
		}
		printf(")\n"); //��������������
	}
	return 0;
}

//����ѵ�����(��Ҫ��  ����Ĳ�ͬ  )��Ϥfgets(char *s,int n,sstream)���÷�
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

const int maxn = 200 + 10;
using namespace std;
char s[maxn][maxn];
int n;

void DFS(int r, int c) {
	printf("%c(", s[r][c]);
	if (r + 1 < n && s[r + 1][c] == '|') {
		int i = c;
		while (s[r + 2][i - 1] == '-'&& i - 1 >= 0)i--;
		while (s[r + 2][i] == '-' && s[r + 3][i] != '\0') {
			if (!isspace(s[r + 3][i]))DFS(r + 3, i);
			i++;
		}
	}
	printf(")");
}

int main() {
	//freopen("in.txt", "r", stdin);
	int T;
	fgets(s[0], maxn, stdin);  //���ļ�stream�ж�ȡmaxn-1���ַ�/һ�У���һ�в���maxn-1������s�����ַ���//����:http://blog.csdn.net/jackin2/article/details/5573771
	sscanf(s[0], "%d", &T);
	while (T--) {
		n = 0;
		for (;;) {
			fgets(s[n], maxn, stdin);
			if (s[n][0] == '#')break;
			n++;
		}
		printf("(");
		if (n) {
			for (int i = 0; i < strlen(s[0]); i++) {
				if (!isspace(s[0][i])) { DFS(0, i); break; }
			}
		}
		printf(")\n");
	}
	return 0;
}
/*
����:
2
    A
    |
--------
B  C   D
   |   |
 ----- -
 E   F G
#
e
|
----
f g
#
*/