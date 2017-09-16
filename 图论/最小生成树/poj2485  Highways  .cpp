//��Ŀ���ӣ�http://poj.org/problem?id=2485
//��Ŀ���⣺����һЩ��ׯ�ĵ�·�ĳ��ȣ������Щ��ׯ�����������ٵĻ���
//����˼·�����������С��������

#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 501
using namespace std;

const int INF = 65536;
bool vis[maxn];
int n;
int graph[maxn][maxn];

int prim()
{
	int low[maxn];
	int min, sum = 0, p;
	vis[1] = true;
	for (int i = 1; i <= n; i++)
		low[i] = graph[1][i];
	for (int i = 2; i <= n; i++)
	{
		min = INF;
		for (int j = 1; j <= n; j++) //�ҵ�ǰ����һ����Сֵ��
		{
			if (!vis[j] && min > low[j])
			{
				min = low[j];
				p = j;
			}
		}
		if (sum < min)
			sum = min;
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
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			vis[i] = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &graph[i][j]);//graph����������
			}
		cout << prim() << endl;
	}
	return 0;
}
