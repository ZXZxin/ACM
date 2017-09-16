//��Ŀ���ӣ�http://poj.org/problem?id=2352
//��Ŀ���⣺����һЩ���ǣ����������У�Ҫ�����ұ߼����Ϸ�����������
//����˼·��������״������⣨�����⣩

#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxn 32005
using namespace std;

int level[maxn];
int c[maxn];

int lowbit(int x)
{
	return x&(-x);
}

int sum(int i)///��ǰi��ĺͣ���Ŀ�б�ʾ���ǵȼ�
{
	int s = 0;
	while (i > 0)
	{
		s += c[i];
		i -= lowbit(i);
	}
	return s;
}

void updata(int i, int value)
{
	while (i < maxn)
	{
		c[i] += value;
		i += lowbit(i);
	}
}

int main()
{
	int n, x, y;
	memset(c, 0, sizeof(c));
	memset(level, 0, sizeof(level));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		int temp = sum(++x);
		level[temp]++;///����ȼ��ĸ�����1
		updata(x, 1);
	}
	for (int i = 0; i < n; i++)
		cout << level[i] << endl;
	return 0;
}

