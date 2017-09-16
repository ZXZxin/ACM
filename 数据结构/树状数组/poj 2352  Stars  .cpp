//题目链接：http://poj.org/problem?id=2352
//题目大意：给定一些星星，按坐标排列，要求其右边及其上方的星星数量
//解题思路：利用树状数组求解（基础题）

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

int sum(int i)///求前i项的和，题目中表示的是等级
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
		level[temp]++;///这个等级的个数加1
		updata(x, 1);
	}
	for (int i = 0; i < n; i++)
		cout << level[i] << endl;
	return 0;
}

