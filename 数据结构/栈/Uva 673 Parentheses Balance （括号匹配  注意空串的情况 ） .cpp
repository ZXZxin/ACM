//��Ŀ���ӣ�https://vjudge.net/contest/169967#problem/A
//��Ŀ����: ��ž�������ƥ��
//����˼·: ע��մ��������  OK 

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

const int maxn = 1000 + 10;
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	char str[maxn];
	stack<char>s;
	scanf("%d", &n);
	getchar();
	while (n--) {
		while (!s.empty())s.pop();
		gets(str);  
		if (strcmp(str, "\n") == 0) { //ע��մ������
			printf("Yes\n");
			continue;
		}
		int len = strlen(str);
		bool flag = true;
		for (int i = 0; i < len; i++) {
			if (!s.empty() && ((str[i] == ')' && s.top() == '(') || (str[i] == ']') && s.top() == '['))s.pop();
			else if(str[i] == '(' || str[i] == '[')s.push(str[i]);
			else { flag = false; break; }
		}
		if (s.empty() && flag )printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}