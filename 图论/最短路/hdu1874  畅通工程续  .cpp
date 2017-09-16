//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1874
//题目大意：简单最短路
//解题思路：熟悉各种最短路写法

//（1）dijkstra
#include <iostream>
#include <string.h>
#include <stdio.h>
#define maxn 1000
#define INF 0x1f1f1f1f
using namespace std;


bool flag[maxn];
int graph[maxn][maxn];
int low[maxn];

void DIJ(int n, int s)
{
	memset(flag, false, sizeof(flag));
	flag[s] = true;
	for (int i = 0; i < n; i++)
		low[i] = graph[s][i];
	for (int i = 1; i < n; i++)
	{
		int min = INF, p;
		for (int j = 0; j < n; j++)
			if (!flag[j] && min > low[j])
			{
				min = low[j];
				p = j;
			}
		flag[p] = true;
		for (int j = 0; j < n; j++)
			if (!flag[j] && low[j] > graph[p][j] + low[p])
				low[j] = graph[p][j] + low[p];
	}
}

int main()
{
	int n, m, begin, t;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = INF;
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if (z < graph[x][y])
				graph[x][y] = graph[y][x] = z;
		}
		cin >> begin >> t;
		DIJ(n, begin);
		if (low[t] < INF)
			cout << low[t] << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}


//(2)pair
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x1f1f1f1f
using namespace std;

const int maxn = 1000;
vector<pair<int, int> >Edge[maxn];

int n, m;
int dist[maxn];

void init()
{
	for (int i = 0; i < maxn; i++)Edge[i].clear();
	for (int i = 0; i < maxn; i++)dist[i] = INF;
}

int main()
{
	int begin, t;
	while (cin >> n >> m)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			Edge[x].push_back(make_pair(y, z));
			Edge[y].push_back(make_pair(x, z));
		}
		cin >> begin >> t;
		priority_queue<pair<int, int>>q;
		dist[begin] = 0;
		q.push(make_pair(-dist[begin], begin));
		while (!q.empty())
		{
			int now = q.top().second;
			q.pop();
			for (int i = 0; i < Edge[now].size(); i++)
			{
				int v = Edge[now][i].first;
				if (dist[v] > dist[now] + Edge[now][i].second)
				{
					dist[v] = dist[now] + Edge[now][i].second;
					q.push(make_pair(-dist[v], v));
				}
			}
		}
		if (dist[t] < INF)
			cout << dist[t] << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}

//(3)bellman_ford
#include <iostream>
#include <stdio.h>
#define maxn 1000
#define INF 0x1f1f1f1f
using namespace std;

struct Edge
{
	int u, v;
	int weight;
};
Edge edge[maxn * 2];

int dist[maxn];

void bellman_ford(int begin, int n, int m)
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[begin] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * m; j++)
			if (dist[edge[j].u] > dist[edge[j].v] + edge[j].weight)
				dist[edge[j].u] = dist[edge[j].v] + edge[j].weight;
}


int main()
{
	int n, m, begin, t;
	while (cin >> n >> m)
	{
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].weight);
			edge[i + m].v = edge[i].u;
			edge[i + m].u = edge[i].v;
			edge[i + m].weight = edge[i].weight;
		}
		cin >> begin >> t;
		bellman_ford(begin, n, m);
		if (dist[t] < INF)
			cout << dist[t] << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}

//(4)floyd
#include <iostream>
#include <string.h>
#include <stdio.h>
#define maxn 1000
#define INF 0x1f1f1f1f
using namespace std;

int graph[maxn][maxn];
int low[maxn];

void floyd(int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main()
{
	int n, m, begin, t;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = INF;
		for (int i = 1; i <= m; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if (graph[x][y] > z)
				graph[x][y] = graph[y][x] = z;
		}
		floyd(n);
		scanf("%d%d", &begin, &t);
		if (graph[begin][t] < INF)
			cout << graph[begin][t] << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}


//(5)SPFA
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#define maxn  1000
#define INF 0x1f1f1f1f
using namespace std;


int graph[maxn][maxn];
int flag[maxn];
int dist[maxn];


void SPFA(int begin, int n)
{
	queue<int>q;
	memset(flag, false, sizeof(flag));
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	q.push(begin);
	dist[begin] = 0;
	flag[begin] = true;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		flag[temp] = false;
		for (int i = 0; i < n; i++)
		{
			if (dist[i] > dist[temp] + graph[temp][i])
			{
				dist[i] = dist[temp] + graph[temp][i];
				if (!flag[i])
				{
					q.push(i);
					flag[i] = true;
				}
			}
		}
	}
}


int main()
{
	int n, m, begin, t;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = INF;
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			if (z < graph[x][y])
				graph[x][y] = graph[y][x] = z;
		}
		cin >> begin >> t;
		SPFA(begin, n);
		if (dist[t] < INF)
			cout << dist[t] << endl;
		else cout << "-1" << endl;

	}
	return 0;
}

//(6)pair+SPFA
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x1f1f1f1f
using namespace std;

const int maxn = 1000;
vector<pair<int, int> >Edge[maxn];

int n, m;
int dist[maxn];
bool flag[maxn];

void init()
{
	for (int i = 0; i < maxn; i++)Edge[i].clear();
	for (int i = 0; i < maxn; i++)flag[i] = false;
	for (int i = 0; i < maxn; i++)dist[i] = INF;
}

int main()
{
	int begin, t;
	while (cin >> n >> m)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			Edge[x].push_back(make_pair(y, z));
			Edge[y].push_back(make_pair(x, z));
		}
		cin >> begin >> t;
		queue<int>q;
		dist[begin] = 0;
		flag[begin] = true;
		q.push(begin);
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			flag[now] = false;
			for (int i = 0; i < Edge[now].size(); i++)
			{
				int v = Edge[now][i].first;
				if (dist[v] > dist[now] + Edge[now][i].second)
				{
					dist[v] = dist[now] + Edge[now][i].second;
					if (!flag[Edge[now][i].first])
					{
						q.push(Edge[now][i].first);
						flag[Edge[now][i].first] = true;
					}
				}
			}
		}
		if (dist[t] < INF)
			cout << dist[t] << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}

