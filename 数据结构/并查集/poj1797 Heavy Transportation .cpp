//题目链接：http://poj.org/problem?id=1797
//题目大意：给定一个无向图，求从1到n的路径上的最小值的最大值。
          //就是说，从1到n可能有多条路径，每条路径上都有一个权值最小的边，问这些边的最大值。
//解题思路：（1）并查集：先对每组数据从大到小排序，再按并查集合并，再找到find(1)==find(n),n的重量就是答案
          //（2）二分+并查集
          //（3）kruskal
         // （4）BFS

//(1)
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100010
using namespace std;

int father[maxn];

struct node
{
	int x, y, weight;
}m[maxn];

int cmp(void const *a, void const *b)
{
	return (*(node*)b).weight > (*(node*)a).weight ? 1 : -1;
}

int find(int v)
{
	if (father[v] == v)return v;
	return father[v] = find(father[v]);
}

void  join(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		father[fy] = fx;
}

int main()
{
	int t, ans, k, n;
	cin >> t;
	int kase = 0;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			father[i] = i;
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d%d", &m[i].x, &m[i].y, &m[i].weight);
		}
		qsort(m, k, sizeof(m[0]), cmp);
		for (int i = 0; i < k; i++)
		{
			join(m[i].x, m[i].y);
			if (find(n) == find(1))
			{
				ans = m[i].weight;
				break;
			}
		}
		cout << "Scenario #" << ++kase << ":" << endl;
		cout << ans << endl << endl;
	}
	return 0;
}

//(2)
#include <iostream>
#include <stdio.h>
#define maxn 1010
#define INF 10000000
using namespace std;

int x[maxn*maxn], y[maxn*maxn], cost[maxn*maxn];
int father[maxn];
int ranks[maxn];
int n, m;

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


int judge(int v)
{
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 1; i <= m; i++)
	{
		if (cost[i] >= v)
			join(x[i], y[i]);
	}
	return find(1) == find(n);
}

int erfen()
{
	int l = 1, r = 1e6 + 50;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (judge(mid))
			l = mid + 1;
		else r = mid;
	}
	return l;
}

int main()
{
	int T, kase = 0;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &x[i], &y[i], &cost[i]);
		}
		cout << "Scenario #" << ++kase << ":" << endl;
		cout << erfen() - 1 << endl << endl;
	}
	return 0;
}

//(3)
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define maxn 100010
using namespace std;

int father[maxn];
int r[maxn];


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
	{
		father[a] = b;
	}
	else if (r[a] > r[b])
	{
		father[b] = a;
	}
	else
	{
		father[a] = b;
		r[b]++;
	}
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		r[i] = 1;
	}
}

struct Edge
{
	int u, v;
	int weight;
};

struct Edge edge[maxn];

int cmp(void const *a, void const *b)
{
	return (*(Edge*)a).weight < (*(Edge*)b).weight ? 1 : -1;
}


int Kuaskal(int n, int m)
{
	qsort(edge, m, sizeof(edge[0]), cmp);
	int sum = 0;
	int cnt = 0;///已经加入的边的数量
	for (int i = 0; i < m; i++)
	{
		if (find(1) == find(n))break;
		int u = edge[i].u;
		int v = edge[i].v;
		if (find(u) != find(v))
		{
			cnt++;
			sum = edge[i].weight;
			join(u, v);
		}
		if (cnt == n - 1)return sum;
	}
	return -1;
}

int main()
{
	int T, n, m, kase = 0;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		init(n);
		for (int i = 0; i < m; i++)
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].weight);
		cout << "Scenario #" << ++kase << ":" << endl;
		cout << Kuaskal(n, m) << endl << endl;
	}
	return 0;
}


(4)//BFS+邻接表
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#define maxn 1005

using namespace std;

int n, m;
int edge_cnt;

int head[maxn];
int next_arc[maxn*maxn];
int point[maxn*maxn];
int weight[maxn*maxn];

int dis[maxn];
bool flag[maxn];

void add_edge(int u, int v, int w)
{
	next_arc[edge_cnt] = head[u];
	point[edge_cnt] = v;
	weight[edge_cnt] = w;
	head[u] = edge_cnt;
}

void fun()
{
	memset(dis, 0, sizeof(dis));
	memset(flag, 0, sizeof(flag));

	queue<int>q;
	q.push(1);
	flag[1] = 1;
	dis[1] = 0x1f1f1f1f;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		flag[u] = 0;

		for (int e = head[u]; e != -1; e = next_arc[e])
		{
			int v = point[e];
			if (weight[e] < dis[u])
			{
				if (weight[e] > dis[v])
				{
					dis[v] = weight[e];
					if (!flag[v])
						q.push(v);
				}
			}
			else if (dis[v] < dis[u])
			{
				dis[v] = dis[u];
				if (!flag[v])
					q.push(v);
			}
		}
	}
}

int main()
{
	int t, kase = 0;
	cin >> t;
	while (t--)
	{
		memset(head, -1, sizeof(head));
		edge_cnt = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edge_cnt++;
			add_edge(u, v, w);
			edge_cnt++;
			add_edge(v, u, w);
		}
		fun();
		cout << "Scenario #" << ++kase << ":" << endl;
		cout << dis[n] << endl << endl;
	}
	return 0;
}

