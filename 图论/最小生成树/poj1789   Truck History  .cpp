//题目链接：http://poj.org/problem?id=1789
//题目大意：题意：输入1个n，代表有多少组字符数组。每个数组都只有7个字符，
          //每2个数组不同字符的个数代表这2个字符串的距离（假设为距离）。现在要你构建一棵树，使得所花费的距离最小
//解题思路：利用prim或者kruskal求解最小生成树即可

//（1）
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#define maxn 3000
#define INF 65536
using namespace std;

int cost[maxn][maxn];
bool vis[maxn];
int low[maxn];

int prim(int n)
{
	int sum = 0, p, min;
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	vis[1] = true;
	for (int i = 1; i <= n; i++)
		low[i] = cost[1][i];
	for (int i = 2; i <= n; i++)
	{
		min = INF, p = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && min > low[j])
			{
				min = low[j];
				p = j;
			}
		vis[p] = true;
		sum += min;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && low[j] > cost[p][j])
				low[j] = cost[p][j];
	}
	return sum;
}

int cacluate(char *a, char *b)
{
	int count = 0;
	for (int k = 0; k < 7; k++)
		if (a[k] != b[k])count++;
	return count;

}

int main(int argc, char const *argv[])
{
	int n;
	char str[maxn][9];
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)break;
		for (int i = 1; i <= n; i++)
			scanf("%s", str[i]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
				cost[i][j] = cost[j][i] = cacluate(str[i], str[j]);
		}
		cout << "The highest possible quality is 1/" << prim(n) << "." << endl;
	}
	return 0;
}


//（2）
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxn 2010
#define maxm 2000*2000+10
using namespace std;

int father[maxn];
int r[maxn];
char str[maxn][maxn];

struct Edge
{
	int u, v;
	int weight;
};
Edge edge[maxm];

int cmp(Edge a, Edge b)
{
	return a.weight < b.weight;
}

int find(int v)
{
	if (v == father[v])return v;
	return father[v] = find(father[v]);
}

void join(int u, int v)
{
	int a = find(u);
	int b = find(v);
	if (a == b)return;
	if (r[a] < r[b])
		father[a] = b;
	else if (r[b] < r[a])
		father[b] = a;
	else
	{
		father[a] = b;
		r[b]++;
	}
}

int Kruskal(int n, int m)
{
	sort(edge, edge + m, cmp);
	int sum = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		if (find(u) != find(v))
		{
			cnt++;
			sum += edge[i].weight;
			father[find(u)] = find(v);
			join(u, v);
		}
		if (n - 1 == cnt)return sum;
	}
	return -1;
}

int cacluate(char *a, char *b)
{
	int count = 0;
	for (int k = 0; k < 7; k++)
		if (a[k] != b[k])
			count++;
	return count;
}

int main()
{
	int n;
	while (cin >> n&&n)
	{
		for (int i = 1; i <= n; i++)
			scanf("%s", str[i]);
		for (int i = 1; i <= n; i++)
		{
			father[i] = i;
			r[i] = i;
		}
		int res = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				edge[res].u = i;
				edge[res].v = j;
				edge[res++].weight = cacluate(str[i], str[j]);
			}
		}
		cout << "The highest possible quality is 1/" << Kruskal(n, res) << "." << endl;
	}
	return 0;
}


