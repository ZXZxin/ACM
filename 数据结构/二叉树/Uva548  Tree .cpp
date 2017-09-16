//题目链接：https://vjudge.net/contest/171957#problem/H
//题目大意：给出一棵点带权的二叉树的中序和后序遍历，
         // 找一个叶子使得它到根的路径上的权和最小
         //如果有多解，该叶子本身的权应该尽量小
//解题思路：在中序遍历中找到后序遍历的第一个字符（根），然后建树


//（1）数组实现：
#include <iostream>
#include <sstream>
#include <string>
#define maxn 10000+10
using namespace std;

int inorder[maxn], post[maxn], lch[maxn], rch[maxn];
int n;

bool read(int *a)
{
	string line;
	if (!getline(cin, line))return false;
	stringstream ss(line);
	n = 0;
	int x;
	while (ss >> x)a[n++] = x;
	return n > 0;
}

int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1)return 0;
	int root = post[R2];
	int p = L1;
	while (inorder[p] != root)p++;
	int cnt = p - L1;
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}

int best_sum, best;

void dfs(int u, int sum)
{
	sum += u;
	if (!lch[u] && !rch[u])
	{
		if (best_sum > sum || (best_sum == sum&&u < best))
		{
			best_sum = sum;
			best = u;
		}
	}
	if (lch[u])dfs(lch[u], sum);
	if (rch[u])dfs(rch[u], sum);
}


int main()
{
	while (read(inorder))
	{
		read(post);
		build(0, n - 1, 0, n - 1);
		best_sum = 1000000000;
		dfs(post[n - 1], 0);
		cout << best << endl;
	}
	return 0;
}
//指针实现：
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define maxn 10000+10
using namespace std;

int Inorder[maxn], Post[maxn];
int cnt, ans;
int best_sum, best;

typedef struct BiNode
{
	int data;
	struct BiNode *left, *right;
} BiNode, *BiTree;

/*BiNode node[maxn];

BiTree NewNode()
{
    node[ans].left=NULL;
    node[ans].right=NULL;
    return &node[ans++];
}
*/
void input()
{
	cnt = 1;
	while (getchar() != '\n')
		scanf("%d", &Inorder[cnt++]);
	for (int i = -0; i < cnt; i++)
		cin >> Post[i];
}

BiTree Creat(int *mid, int *post, int len)
{
	if (len == 0)
		return NULL;
	int p = len - 1;
	while (mid[p] != post[len - 1])--p;
	//BiTree u=NewNode();
	BiTree u = (BiTree)malloc(sizeof(BiNode));
	u->data = post[len - 1];
	u->left = Creat(mid, post, p);
	u->right = Creat(mid + p + 1, post + p, len - p - 1);
	return u;
}

void dfs(BiTree T, int sum)
{
	sum += T->data;
	if (!T->left && !T->right)
	{
		if (sum < best_sum || (sum == best_sum&&T->data < best))
		{
			best_sum = sum;
			best = T->data;
		}
	}
	if (T->left)dfs(T->left, sum);
	if (T->right)dfs(T->right, sum);
}

int main()
{
	while (cin >> Inorder[0])
	{
		//ans=0;
		input();
		BiTree root = NULL;
		root = Creat(Inorder, Post, cnt);
		best_sum = 1000000000;
		dfs(root, 0);
		cout << best << endl;
	}
	return 0;
}