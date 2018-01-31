//题目链接：https://vjudge.net/contest/169966#problem/T
//题目大意：给你n个点，m条边，求从起点 1 到 终点 n 的最短距离，同时要保证 每条边颜色的字典序 最小，而且还有重边以及自环
//解题思路: 运用反向和正向BFS两次求解，第一次反向BFS求出每个点到n的最短距离，然后从 起点开始BFS，
           //每一次到达一个新的结点的时候要保证 d 值恰好 减1，就像 从起点到终点 有 很多层 (因为可以有重边) ,每一层要选择最小的 颜色 然后直到终点

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

const int maxn = 1e5 + 10;
const int INF = 1e9;
using namespace std;
int n, m;

struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0) :u(u), v(v), w(w) {}
};

vector<Edge>edge;
vector<int>G[maxn];
int d[maxn];
bool vis[maxn];

void addedge(int u, int v, int w) {
	edge.push_back(Edge(u, v, w));
	int len = edge.size() - 1;
	G[u].push_back(len); //记录 u 连的边 在 edge 中的位置
}

void rev_bfs() {  //先做一个反向的bfs求出  每个点到 n 的最小距离
	memset(vis, false, sizeof(vis));
	queue<int>q;
	d[n] = 0;
	q.push(n);
	vis[n] = true;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < G[now].size(); i++) {
			if (!vis[edge[G[now][i]].v]) {
				vis[edge[G[now][i]].v] = true;
				d[edge[G[now][i]].v] = d[now] + 1;//  计算长度//寻找每一个的最短路
				q.push(edge[G[now][i]].v);
			}
		}
	}
}
void bfs() {
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	int minn;   // 记录  每一层  最小的颜色
	vector<int>ans;
	vector<int>next;
	vector<int>next2;
	next.push_back(1);//目前这一层
	for (int i = 0; i < d[1]; i++) { //  1 到 n 总共 有 d[1]  层
		minn = INF;
		for (int j = 0; j < next.size(); j++) {// 每 一层 的所有的满足的点
			for (int k = 0; k < G[next[j]].size(); k++) {
				if (d[next[j]] == d[edge[G[next[j]][k]].v] + 1) {
					minn = min(minn, edge[G[next[j]][k]].w);
				}
			}
		}
		ans.push_back(minn);//将每一层的最小的颜色存到 答案 中
		next2.clear();
		for (int j = 0; j < next.size(); j++) {// 找出下一层
			for (int k = 0; k < G[next[j]].size(); k++) {
				if (d[next[j]] == d[edge[G[next[j]][k]].v] + 1 && !vis[edge[G[next[j]][k]].v] && edge[G[next[j]][k]].w == minn) {
					vis[edge[G[next[j]][k]].v] = true;
					next2.push_back(edge[G[next[j]][k]].v);
				}
			}
		}
		next = next2;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size() - 1; i++)printf("%d ", ans[i]);
	printf("%d\n", ans[ans.size() - 1]);
}

int main() {
	//freopen("in.txt", "r", stdin);
	int u, v, w;
	while (scanf("%d%d", &n, &m) != EOF) {
		edge.clear();
		for (int i = 0; i <= n; i++)G[i].clear();
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w);
			addedge(v, u, w);
		}
		rev_bfs();
		bfs();
	}
	return 0;
}
