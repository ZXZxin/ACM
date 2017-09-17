//poj2253
//题目链接：http://poj.org/problem?id=2253
//题目大意：一只青蛙想从自己脚下的石头开始调到另一只青蛙的石头上，
          /* 它可以直接跳，也可以借助别的空石头跳。
		     输入的数据是每个石头的坐标。
             问最短的青蛙距离（从一块石头到另一块石头的最大距离）。
		     实际上就是求最短路径中的前后两个点的距离中的最大值。
             实际上这道题就是求最小生成树中的最大权值。*/
//解题思路：可用dijkstra的变式求解


#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#define maxn 1000
#define INF 0x1f1f1f1f
using namespace std;

double map[maxn][maxn];
int flag[maxn];
double low[maxn];

struct node
{
	int x, y;
} m[maxn];

double cacluate(node a, node b)
{
	return sqrt(double((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y)));
}

void DIJ(int n)
{
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; ++i)
		low[i] = map[1][i];
	flag[1] = true;
	low[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		double min1 = INF;
		int p;
		for (int j = 1; j <= n; j++)
			if (!flag[j] && min1 > low[j])
			{
				p = j;
				min1 = low[j];
			}
		flag[p] = true;
		for (int j = 1; j <= n; j++)
			low[j] = min(low[j], max(min1, map[p][j]));
	}
}

int main()
{
	int n, kase = 0;
	while (cin >> n&&n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> m[i].x >> m[i].y;
		}
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
			{
				map[i][j] = map[j][i] = cacluate(m[i], m[j]);
			}
		DIJ(n);
		if (kase)cout << endl;
		cout << "Scenario #" << ++kase << endl;
		printf("Frog Distance = %.3f\n", low[2]);
	}
	return 0;
}


//poj1797
//题目链接：http://poj.org/problem?id=1797
//题目大意：从一个点到另一个点有很多路径，求这些路径中的最大值的最小值（最大承重量）
//解题思路：用dijkstra的变式也可求解

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 1005
#define INF 0x3f3f3f3f
using namespace std;

int map[maxn][maxn];
bool visit[maxn];
int dist[maxn];

void DIJ(int n)
{
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; i++)
		dist[i] = map[1][i];
	dist[1] = 0;
	visit[1] = true;
	for (int i = 2; i <= n; i++)
	{
		int min1 = -INF, p;
		for (int j = 1; j <= n; j++)
			if (!visit[j] && min1 < dist[j])
			{
				min1 = dist[j];
				p = j;
			}
		visit[p] = true;
		for (int j = 1; j <= n; j++)
		{
			if (visit[j])continue;
			dist[j] = max(dist[j], min(map[p][j], min1));
		}
	}
}


int main()
{
	int T, n, m;
	cin >> T;
	int kase = 0;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)map[i][j] = 0;
				else map[i][j] = -INF;
				for (int i = 1; i <= m; i++)
				{
					int x, y, z;
					scanf("%d%d%d", &x, &y, &z);
					map[x][y] = map[y][x] = z;
				}
				DIJ(n);
				cout << "Scenario #" << ++kase << ":" << endl;
				cout << dist[n] << endl << endl;
	}
	return 0;
}


