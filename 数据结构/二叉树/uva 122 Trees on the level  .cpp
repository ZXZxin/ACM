//题目链接：https://vjudge.net/contest/171957#problem/G
//题目大意：输入一棵二叉树，从左到右输出各个结点的值
         //每个结点都按照从根节点到它的移动序列给出
//解题思路：建树，然后BFS输出

#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1000
using namespace std;

char str[maxn];
bool faild;
vector<int>ans;

typedef struct Node
{
	int v;
	bool have_value;
	struct Node *left, *right;
} BiNode, *BiTree;

BiTree root;

void remove_tree(BiTree T)
{
	if (!T)return;
	remove_tree(T->left);
	remove_tree(T->right);
	free(T);
}

BiTree newnode()
{
	BiTree u = (BiTree)malloc(sizeof(BiNode));
	if (u)
	{
		u->left = u->right = NULL;
		u->have_value = 0;
	}
	return u;
}

void addnode(int v, char *s)
{
	BiTree u = root;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == 'L')
		{
			if (!u->left)u->left = newnode();
			u = u->left;
		}
		else if (s[i] == 'R')
		{
			if (!u->right)u->right = newnode();
			u = u->right;
		}
	}
	if (u->have_value)faild = 1;
	u->v = v;
	u->have_value = true;
}


bool read()
{
	faild = false;
	remove_tree(root);
	root = newnode();
	while (1)
	{
		if (scanf("%s", str) != 1)return false;
		if (!strcmp("()", str))break;
		int v;
		sscanf(&str[1], "%d", &v);
		addnode(v, strchr(str, ',') + 1);
	}
	return true;
}

bool BFS()
{
	ans.clear();
	queue<BiTree>q;
	q.push(root);
	while (!q.empty())
	{
		BiTree u = q.front();
		q.pop();
		if (!u->have_value)return false;
		ans.push_back(u->v);
		if (u->left)q.push(u->left);
		if (u->right)q.push(u->right);
	}
	return true;
}

int main()
{
	while (read())
	{
		if (faild || !BFS())
			cout << "not complete" << endl;
		else
		{
			vector<int>::iterator  it;
			for (it = ans.begin(); it != ans.end() - 1; it++)
				cout << *it << " ";
			cout << *(ans.end() - 1) << endl;
		}
	}
	return 0;
}