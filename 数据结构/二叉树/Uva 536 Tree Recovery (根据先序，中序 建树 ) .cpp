//题目链接：https://vjudge.net/contest/169967#problem/C
//题目大意: 给你先序和中序遍历，要你输出后序遍历
//解题思路: 通过先序遍历确定 根节点在中序遍历中的位置，然后求出 各子树的长度，然后递归建树即可
          //学习博客:http://blog.csdn.net/u010667082/article/details/46274447


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>

const int maxn = 1000 + 10;
using namespace std;

typedef struct node {
	char value;
	struct node *left, *right;
}BiNode,*BiTree;

BiTree Build(char *pre, char *in, int len) {
	if (len <= 0 || pre == NULL || in == NULL)return NULL;
	int leftlen, rightlen, i = 0;
	BiTree root = new BiNode();
	root->value = pre[i];
	root->left = root->right = NULL;
	while (i < len && in[i] != pre[0])i++;
	leftlen = i;
	rightlen = len - leftlen - 1;
	if (leftlen)root->left = Build(pre + 1, in, leftlen);
	if (rightlen)root->right = Build(pre + leftlen + 1, in + leftlen + 1, rightlen);
	return root;
}

void postOrder(BiTree root) {
	if (root) {
		postOrder(root->left);
		postOrder(root->right);
		printf("%c", root->value);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	char pre[maxn], in[maxn];
	while (scanf("%s%s", pre, in) != EOF) {
		int len = strlen(pre);
		BiTree root = new BiNode();
		root = Build(pre, in, len);
		postOrder(root);
		printf("\n");
	}
	return 0;
}
