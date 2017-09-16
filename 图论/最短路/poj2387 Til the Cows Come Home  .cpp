//题目链接：http://poj.org/problem?id=2387
//题目大意：从第一个点到最后一个点的最短路
//解题思路：模板题


//（1）
#include <iostream>
#include <string.h>
#include <algorithm>
#define maxn 1010
#define INF 9999999
using namespace std;

int map[maxn][maxn];
bool flag[maxn];
int dist[maxn];

void DIJ(int n)
{
	memset(flag, false, sizeof(flag));
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;
	///flag[1]=true;大错特错
	for (int i = 2; i <= n; i++)
	{
		int min1 = INF, p;
		for (int j = 1; j <= n; j++)
			if (!flag[j] && min1 > dist[j])
			{
				min1 = dist[j];
				p = j;
			}
		flag[p] = true;
		for (int y = 1; y <= n; y++)
			dist[y] = min(dist[y], dist[p] + map[p][y]);
	}
}

int main()
{
	int n, m;
	cin >> m >> n;
	memset(map, INF, sizeof(map));
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (map[x][y] > z)
			map[x][y] = map[y][x] = z;
	}
	DIJ(n);
	cout << dist[n];
	return 0;
}


//（2）dijkstra+队列优化
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#define maxn 1000
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int dist[maxn];
int flag[maxn];


struct HeapNode
{
	int d, u;
	HeapNode(int d, int u) :d(d), u(u) {}
	bool operator < (const HeapNode &rhs)const
	{
		return d > rhs.d;
	}
};

struct Edge
{
	int from, to, weight;
};

vector<Edge>edge;
vector<int>G[maxn];

void init()
{
	for (int i = 1; i <= n; i++)
		G[i].clear();
	edge.clear();
}

void addedge(int from, int to, int cost)
{
	edge.push_back((Edge) { from, to, cost });
	int len = edge.size();
	G[from].push_back(len - 1);
}

void DIJ(int s)
{
	priority_queue<HeapNode>q;
	memset(flag, false, sizeof(flag));
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[s] = 0;
	q.push((HeapNode) { 0, s });
	while (!q.empty())
	{
		HeapNode x = q.top();
		q.pop();
		int u = x.u;
		if (flag[u])continue;
		flag[u] = true;
		for (int i = 0; i < G[u].size(); i++)
		{
			Edge& e = edge[G[u][i]];
			if (dist[e.to] > dist[u] + e.weight)
			{
				dist[e.to] = dist[u] + e.weight;
				q.push(HeapNode(dist[e.to], e.to));
			}
		}

	}


}

int main(int argc, char const *argv[])
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		addedge(x, y, z);
		addedge(y, x, z);
	}
	DIJ(1);
	cout << dist[n];
	return 0;
}

//（3）dijkstra+make_pair
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define maxn 1010
#define INF 9999999
using namespace std;

vector<pair<int, int> >Edge[maxn];

int map[maxn][maxn];
int dist[maxn];

void DIJ(int n)
{

	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;
	priority_queue<pair<int, int> >q;
	q.push(make_pair(-dist[1], 1));
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
}

int main()
{
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < maxn; i++)Edge[i].clear();
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		Edge[x].push_back(make_pair(y, z));
		Edge[y].push_back(make_pair(x, z));
	}
	DIJ(n);
	cout << dist[n];
	return 0;
}




