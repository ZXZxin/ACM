//��Ŀ���ӣ�http://poj.org/problem?id=1611
//��Ŀ���⣺������Ⱦ������ͨ��һЩ���ŽӴ�
          //����һЩ���ţ����ж����˱���Ⱦ
//����˼·�����鼯�ҳ��������ȣ����뼯��


//˳����ranks��¼�����Ż�
#include <iostream>
#define maxn 30001
using namespace std;

int father[maxn];
int ranks[maxn];

int find(int v)
{
	if (father[v] == v)
		return v;
	return father[v] = find(father[v]);
}

void join(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy)return;
	if (ranks[fx] < ranks[fy])
	{
		father[fx] = fy;
	}
	else
	{
		father[fy] = fx;
		if (ranks[fx] == ranks[fy])
			ranks[fy]++;
	}
}

int main()
{
	int n, m, k, x, y;
	while (cin >> n >> m && (n || m))
	{
		int sum = 1;
		for (int i = 0; i < n; i++)
		{
			father[i] = i;
			ranks[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> k;
			if (k >= 1)
				cin >> x;
			for (int j = 1; j < k; j++)
			{
				cin >> y;
				join(x, y);
			}
		}
		for (int i = 1; i < n; i++)
		{
			if (find(0) == find(i))
				sum++;
		}
		cout << sum << endl;
	}
	return 0;
}