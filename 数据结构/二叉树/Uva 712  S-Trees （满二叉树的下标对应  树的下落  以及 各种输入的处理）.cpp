//题目链接：https://vjudge.net/contest/169967#problem/B
//题目大意: 就是给你一颗满二叉树,每一层代表一个01变量,给你叶子的值,要你从根节点开始走,给你一个序列按照那个序列,0往左,1往右,求最后到达叶子的值
//解题思路: 这一题学到了很多输入的 知识，这些也是基本的知识，如不知道输入字符是采用"%1d"输入数字，以及二叉树的对应下标

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>

const int maxn = 1<<10;
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, kase = 0;
	int a[maxn],dep[maxn],leaf[maxn], ans[maxn];//dep存的是 i 层的 x编号 ，leaf存的是 叶子的数，ans保存答案
	while (scanf("%d", &n) != EOF && n != 0) {
		getchar();//只要有输入 char,或者 char*,就要getchar()一下
		for (int i = 0; i < n; i++) {
			getchar();
			scanf("%d", &dep[i]);
			getchar();
		}
		for(int i = pow(2,n); i <= pow(2,n+1) - 1; i++)scanf("%1d",&leaf[i]);//n + 1层的叶子
		scanf("%d", &m);
		int k = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= n; j++)scanf("%1d",&a[j]);//注意值 //这里输入的是每一次的测试样例
			int x = 1;
			for (int j = 0; j < n; j++) {
				if (a[dep[j]] == 0)x *= 2;
				else if(a[dep[j]] == 1)x = x * 2 + 1;
			}
			ans[k++] = leaf[x];
		}
		printf("S-Tree #%d:\n",++kase);
		for (int i = 0; i < k; i++)printf("%d", ans[i]);
		printf("\n\n");
	}
	return 0;
}
