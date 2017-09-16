//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1805
//题目大意：给出后缀表达式，求出该表达式层次遍历的逆序
//解题思路：遇到小写建树，并入栈，遇到大写弹出栈顶两个元素，并作为大写的左右儿子建树

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <queue>
#define maxn 100101
using namespace std;

int flag;

typedef struct BiNode
{
	char value;
	struct BiNode *left, *right;
} BiNode, *BiTree;

int main()
{
	int n, cnt;
	char str[maxn];
	char ans[maxn];
	stack<BiTree>s;
	cin >> n;
	while (n--)
	{
		cin >> str;
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			if (str[i] >= 'a'&&str[i] <= 'z')
			{
				BiTree u = (BiTree)malloc(sizeof(BiNode));
				u->value = str[i];
				u->left = u->right = NULL;
				s.push(u);
			}
			else if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				BiTree x, y;
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				BiTree u = (BiTree)malloc(sizeof(BiNode));
				u->value = str[i];
				u->left = y;
				u->right = x;
				s.push(u);
			}
		}
		BiTree u = s.top();
		queue<BiTree>q;
		cnt = 0;
		q.push(u);
		while (!q.empty())
		{
			BiTree v = q.front();
			q.pop();
			ans[cnt++] = v->value;
			if (v->left)q.push(v->left);
			if (v->right)q.push(v->right);
		}
		for (int i = cnt - 1; i >= 0; i--)
			cout << ans[i];
		cout << endl;
		while (!s.empty())s.pop();
	}
	return 0;
}

