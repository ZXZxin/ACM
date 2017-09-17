//poj2253
//��Ŀ���ӣ�http://poj.org/problem?id=2253
//��Ŀ���⣺һֻ��������Լ����µ�ʯͷ��ʼ������һֻ���ܵ�ʯͷ�ϣ�
          /* ������ֱ������Ҳ���Խ�����Ŀ�ʯͷ����
		     �����������ÿ��ʯͷ�����ꡣ
             ����̵����ܾ��루��һ��ʯͷ����һ��ʯͷ�������룩��
		     ʵ���Ͼ��������·���е�ǰ��������ľ����е����ֵ��
             ʵ����������������С�������е����Ȩֵ��*/
//����˼·������dijkstra�ı�ʽ���


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
//��Ŀ���ӣ�http://poj.org/problem?id=1797
//��Ŀ���⣺��һ���㵽��һ�����кܶ�·��������Щ·���е����ֵ����Сֵ������������
//����˼·����dijkstra�ı�ʽҲ�����

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


