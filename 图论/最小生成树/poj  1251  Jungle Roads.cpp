//��Ŀ���ӣ�http://poj.org/problem?id=1251
//��Ŀ���⣺Ҳ������С������������ĳ�������еľ���
//����˼·��prim��⼴��


#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 501
#define MAX 99999999
using namespace std;

const int INF = 65536;
bool vis[maxn];
int n;
int graph[maxn][maxn];

int prim()
{
	memset(vis, 0, sizeof(vis));
	int low[maxn];
	int min, sum = 0, p;
	vis[1] = true;
	for (int i = 1; i <= n; i++)
		low[i] = graph[1][i];
	for (int i = 2; i <= n; i++)
	{
		min = INF;
		p = -1;
		for (int j = 1; j <= n; j++) //�ҵ�ǰ����һ����Сֵ��
		{
			if (!vis[j] && min > low[j])
			{
				min = low[j];
				p = j;
			}
		}
		sum += min;
		vis[p] = true;
		for (int j = 1; j <= n; j++) //����low����
		{
			if (!vis[j] && low[j] > graph[p][j])
			{
				low[j] = graph[p][j];
			}
		}
	}
	return sum;
}

int main()
{
	int k, k2;
	char c, c2;
	while (cin >> n&&n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = MAX;//�ⲽ����Ҫ�������Ŀû�и���ĳһ������Ҫ��MAX
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> c;
			cin >> k;
			if (k > 0)
			{
				for (int j = 0; j < k; j++)
				{
					cin >> c2;
					cin >> k2;
					graph[c - 'A' + 1][c2 - 'A' + 1] = graph[c2 - 'A' + 1][c - 'A' + 1] = k2;
				}
			}
		}
		cout << prim() << endl;
	}
	return 0;
}

