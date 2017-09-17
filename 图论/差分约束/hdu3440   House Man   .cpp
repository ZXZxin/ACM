//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=3440
//题目大意：超人可以在房屋之间跳跃，他想要使得最矮的房子到最高的房子
          /*的距离最远，每个房子的高度不同，跳跃的顺序是从低到高，
            但是他的跳跃距离是有限制的，给出房子个数和超人能跳跃的最大
			距离，以及每个房子的高度，求最大的水平距离*/
//解题思路：此题为差分约束求最短路的题目，首先每两个点的距离大于1，即d[i]-d[i-1]>=1
          //因为是要求最短路，则传换为d[i-1]-d[i]>=-1,其次，要满足每两个点的距离的
          //绝对值大于超人的跳跃距离，这里把绝对值去掉，约定从小到大建边，SPFA求解即可


#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
#define maxn 100010
#define INF 0xf3f3f3f
using namespace std;

int dist[maxn];
int head[maxn];
bool flag[maxn];
int cnt[maxn];
int tol;
int n;

struct Edge {
	int to, v, next;
}edge[maxn];

struct node {
	int h, w;
}a[maxn];

int cmp(node a, node b) {
	return a.h < b.h;
}

void add(int a, int b, int v) {
	edge[tol].to = b;
	edge[tol].v = v;
	edge[tol].next = head[a];
	head[a] = tol++;
}

int SPFA(int begin, int e) {
	memset(cnt, 0, sizeof(cnt));
	memset(flag, false, sizeof(flag));
	memset(dist, INF, sizeof(dist));
	flag[begin] = true;
	dist[begin] = 0;
	cnt[begin] = 1;
	queue<int>q;
	q.push(begin);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		flag[now] = false;
		for (int i = head[now]; i != -1; i = edge[i].next) {
			if (dist[edge[i].to] > dist[now] + edge[i].v) {
				dist[edge[i].to] = dist[now] + edge[i].v;
				if (!flag[edge[i].to]) {
					q.push(edge[i].to);
					flag[edge[i].to] = true;
					if (++cnt[edge[i].to] > n)return -1;//入队超过n次则无解
				}
			}
		}
	}
	return dist[e];
}

int main() {
	//freopen("in.txt", "r", stdin);
	int T, d;
	int kase = 0;
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof(head));
		tol = 0;
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++) {
			cin >> a[i].h;
			a[i].w = i;
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 2; i <= n; i++) {
			if (a[i].w > a[i - 1].w) {
				add(a[i - 1].w, a[i].w, d);
			}
			else {
				add(a[i].w, a[i - 1].w, d);//满足差分约束的条件
			}
			add(i, i - 1, -1);//相邻两点距离大于等于1
		}
		int s = min(a[1].w, a[n].w);
		int e = max(a[1].w, a[n].w);
		cout << "Case " << ++kase << ": ";
		cout << SPFA(s, e) << endl;
	}
	return 0;
}