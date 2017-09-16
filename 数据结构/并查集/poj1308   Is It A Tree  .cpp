//题目链接：http://poj.org/problem?id=1308
//题目大意：给出一些父亲节点和儿子节点，判断一棵树是否满足题目的三个要求
//解题思路：用并查集实现，查找和合并集合
         //注意：
         /*（1）注意空树的情况。
           （2）输入的一组的根相同，也不是。
           （3）森林也不是。
		  */

#include <iostream>
#include <stdio.h>
#define maxn 1010
#define INF 10000000
using namespace std;

int father[maxn];
int ranks[maxn];
bool flag[maxn];


int find(int v)
{
	if (father[v] == v)
		return v;
	return father[v] = find(father[v]);
}

void join(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)return;
	if (ranks[fx] < ranks[fy])
	{
		father[fx] = fy;
	}
	else
	{
		father[fy] = fx;
		if (ranks[fx] == ranks[fy])
			ranks[fy]++;
	}
}

int main()
{
	int x, y, kase = 0;
	while (cin >> x >> y&&x != -1 && y != -1)
	{
		if (x == 0 && y == 0)
		{
			cout << "Case " << ++kase << " is a tree." << endl;
			continue;
		}
		for (int i = 0; i < 110; i++)
		{
			father[i] = i;
			flag[i] = false;
		}
		flag[x] = flag[y] = true;
		int first = x;
		bool tree = true;
		if (x == y)tree = false;
		else join(x, y);

		while (cin >> x >> y && (x != 0))
		{
			flag[x] = flag[y] = true;
			if (find(x) == find(y))tree = false;
			join(x, y);
		}

		for (int i = 1; i < 110; i++)
			if (flag[i] && find(i) != find(first))
			{
				tree = false;
				break;
			}
		if (tree)
			cout << "Case " << ++kase << " is a tree." << endl;
		else cout << "Case " << ++kase << " is not a tree." << endl;
	}
	return 0;
}



