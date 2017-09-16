//poj3169+hdu3592
//差分约束
//给出如果需要求的是两个变量差的最大值，那么需要将所有不等式转变成"<="的形式，建图后求最短路；
//相反，如果需要求的是两个变量差的最小值，那么需要将所有不等式转化成">="，建图后求最长路。
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#define maxn 10010
#define INF 0x3f3f3f3f
#pragma warning(disable:4996)
using namespace std;

int dist[maxn];
int cnt[maxn];
int flag[maxn];
int head[maxn];
int tol;

struct Edge {
	int to, v, next;
}edge[maxn];

void add(int a, int b, int v) {
	edge[tol].to = b;
	edge[tol].v = v;
	edge[tol].next = head[a];
	head[a] = tol++;
}

bool SPFA(int begin, int n) {
	memset(dist, INF, sizeof(dist));
	memset(flag, false, sizeof(flag));
	memset(cnt, 0, sizeof(cnt));
	flag[begin] = true;
	dist[begin] = 0;
	cnt[begin] = 1;
	queue<int>q;
	q.push(begin);
	while (!q.empty()) {
		int now = q.front();
		flag[now] = false;
		q.pop();
		for (int i = head[now]; i != -1; i = edge[i].next) {
			if (dist[edge[i].to] > dist[now] + edge[i].v) {
				dist[edge[i].to] = dist[now] + edge[i].v;
				if (!flag[edge[i].to]) {
					q.push(edge[i].to);
					flag[edge[i].to] = true;
					if (++cnt[edge[i].to] > n)return false;
				}
			}
		}
	}
	return true;
}

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while(T--){
	int n, ml, md;
	scanf("%d%d%d", &n, &ml, &md);
		tol = 0;
		memset(head, -1, sizeof(head));
		for (int i = 1; i <= ml; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			if (x > y)swap(x, y);
			add(x, y, c);
		}
		for (int i = 1; i <= md; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			if (x < y)swap(x, y);
			add(x, y, -c);
		}
		if (!SPFA(1, n)) {
			cout << "-1" << endl;
		}
		else if (dist[n] == INF) {
			cout << "-2" << endl;
		}
		else {
			cout << dist[n] << endl;
		}
	}
	return 0;
}