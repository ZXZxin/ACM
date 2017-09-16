//题目链接：http://poj.org/problem?id=2485
//题目大意：给定一些村庄的道路的长度，求把这些村庄连接起来最少的花费
//解题思路：最基本的最小生成树题

#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 501
using namespace std;

const int INF = 65536;
bool vis[maxn];
int n;
int graph[maxn][maxn];

int prim()
{
	int low[maxn];
	int min, sum = 0, p;
	vis[1] = true;
	for (int i = 1; i <= n; i++)
		low[i] = graph[1][i];
	for (int i = 2; i <= n; i++)
	{
		min = INF;
		for (int j = 1; j <= n; j++) //找当前的下一个最小值，
		{
			if (!vis[j] && min > low[j])
			{
				min = low[j];
				p = j;
			}
		}
		if (sum < min)
			sum = min;
		vis[p] = true;
		for (int j = 1; j <= n; j++) //更新low数组
		{
			if (!vis[j] && low[j] > graph[p][j])
			{
				low[j] = graph[p][j];
			}
		}
	}
	return sum;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			vis[i] = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &graph[i][j]);//graph数组代表距离
			}
		cout << prim() << endl;
	}
	return 0;
}
