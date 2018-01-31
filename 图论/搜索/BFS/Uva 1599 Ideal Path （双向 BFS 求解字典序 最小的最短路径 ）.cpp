//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/T
//��Ŀ���⣺����n���㣬m���ߣ������� 1 �� �յ� n ����̾��룬ͬʱҪ��֤ ÿ������ɫ���ֵ��� ��С�����һ����ر��Լ��Ի�
//����˼·: ���÷��������BFS������⣬��һ�η���BFS���ÿ���㵽n����̾��룬Ȼ��� ��㿪ʼBFS��
           //ÿһ�ε���һ���µĽ���ʱ��Ҫ��֤ d ֵǡ�� ��1������ ����㵽�յ� �� �ܶ�� (��Ϊ�������ر�) ,ÿһ��Ҫѡ����С�� ��ɫ Ȼ��ֱ���յ�

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
	G[u].push_back(len); //��¼ u ���ı� �� edge �е�λ��
}

void rev_bfs() {  //����һ�������bfs���  ÿ���㵽 n ����С����
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
				d[edge[G[now][i]].v] = d[now] + 1;//  ���㳤��//Ѱ��ÿһ�������·
				q.push(edge[G[now][i]].v);
			}
		}
	}
}
void bfs() {
	memset(vis, false, sizeof(vis));
	vis[1] = true;
	int minn;   // ��¼  ÿһ��  ��С����ɫ
	vector<int>ans;
	vector<int>next;
	vector<int>next2;
	next.push_back(1);//Ŀǰ��һ��
	for (int i = 0; i < d[1]; i++) { //  1 �� n �ܹ� �� d[1]  ��
		minn = INF;
		for (int j = 0; j < next.size(); j++) {// ÿ һ�� �����е�����ĵ�
			for (int k = 0; k < G[next[j]].size(); k++) {
				if (d[next[j]] == d[edge[G[next[j]][k]].v] + 1) {
					minn = min(minn, edge[G[next[j]][k]].w);
				}
			}
		}
		ans.push_back(minn);//��ÿһ�����С����ɫ�浽 �� ��
		next2.clear();
		for (int j = 0; j < next.size(); j++) {// �ҳ���һ��
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
