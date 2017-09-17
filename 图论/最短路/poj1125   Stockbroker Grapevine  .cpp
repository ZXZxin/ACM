//��Ŀ���ӣ�http://poj.org/problem?id=1125
//��Ŀ���⣺�������ÿ��������������ֵ����Сֵ
//����˼·������˼·��������floyd���ÿ������֮������·��
         //Ȼ��ö��ÿ�����㣬����������ľ����е����ֵ��Ȼ��ȡö�ٵĸ����������Сֵ


#include <iostream>
#include <string.h>
#include <math.h>
#define maxn 1000
#define INF 0x1f1f1f
using namespace std;

int map[maxn][maxn];
int dist[maxn];

void foyld(int n)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

int main()
{
	int n, m;
	while (cin >> n&&n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				map[i][j] = INF;
				dist[i] = 0;
			}
		for (int i = 1; i <= n; i++)
		{
			cin >> m;
			for (int j = 1; j <= m; j++)
			{
				int x, y;
				cin >> x >> y;
				map[i][x] = y;
			}
		}
		foyld(n);
		int min = INF;
		int p;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i != j&&map[i][j] > dist[i])
					dist[i] = map[i][j];
			}
			if (min > dist[i])
			{
				min = dist[i];
				p = i;
			}
		}
		if (min == INF)cout << "disjoint" << endl;
		else cout << p << " " << min << endl;
	}
	return 0;
}


