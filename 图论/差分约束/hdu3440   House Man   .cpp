//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=3440
//��Ŀ���⣺���˿����ڷ���֮����Ծ������Ҫʹ����ķ��ӵ���ߵķ���
          /*�ľ�����Զ��ÿ�����ӵĸ߶Ȳ�ͬ����Ծ��˳���Ǵӵ͵��ߣ�
            ����������Ծ�����������Ƶģ��������Ӹ����ͳ�������Ծ�����
			���룬�Լ�ÿ�����ӵĸ߶ȣ�������ˮƽ����*/
//����˼·������Ϊ���Լ�������·����Ŀ������ÿ������ľ������1����d[i]-d[i-1]>=1
          //��Ϊ��Ҫ�����·���򴫻�Ϊd[i-1]-d[i]>=-1,��Σ�Ҫ����ÿ������ľ����
          //����ֵ���ڳ��˵���Ծ���룬����Ѿ���ֵȥ����Լ����С���󽨱ߣ�SPFA��⼴��


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
					if (++cnt[edge[i].to] > n)return -1;//��ӳ���n�����޽�
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
				add(a[i].w, a[i - 1].w, d);//������Լ��������
			}
			add(i, i - 1, -1);//�������������ڵ���1
		}
		int s = min(a[1].w, a[n].w);
		int e = max(a[1].w, a[n].w);
		cout << "Case " << ++kase << ": ";
		cout << SPFA(s, e) << endl;
	}
	return 0;
}