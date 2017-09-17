//题目链接：https://vjudge.net/contest/172365#problem/A
//题目大意：函数满足——If x < 10 f(x) = x.
         //If x >= 10 f(x) = a0 * f(x - 1) + a1 * f(x - 2) + a2 * f(x - 3) + …… + a9 * f(x - 10);
         //要求f(k) % mod;
//解题思路：构造矩阵求解10*10矩阵


#include <iostream>
#include <string.h>
#define maxn 4
using namespace std;
typedef long long LL;

int n;
struct Ma
{
	LL m[10][10];
};

void init(Ma &a)
{
	memset(a.m, 0, sizeof(a.m));
	for (int i = 1; i <= 9; i++)
		a.m[i][i - 1] = 1;
}

Ma operator * (const Ma& a, const Ma& b)
{
	Ma c;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			c.m[i][j] = 0;
			for (int k = 0; k < 10; ++k)
			{
				c.m[i][j] += a.m[i][k] * b.m[k][j];
			}
			c.m[i][j] %= n;
		}
	}
	return c;
}

Ma operator ^ (Ma& a, int k)
{
	Ma c;
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		{
			if (i == j)
				c.m[i][j] = 1;
			else
				c.m[i][j] = 0;
		}
	while (k)
	{
		if (k & 1)
			c = a * c;
		k >>= 1;
		a = a * a;
	}
	return c;
}

int main()
{
	int k;
	int a[10];
	while (cin >> k >> n)
	{
		for (int i = 0; i < 10; i++)
			cin >> a[i];
		if (k < 10)
		{
			cout << k%n << endl;
			continue;
		}
		Ma x;
		init(x);
		x.m[0][0] = a[0];
		x.m[0][1] = a[1];
		x.m[0][2] = a[2];
		x.m[0][3] = a[3];
		x.m[0][4] = a[4];
		x.m[0][5] = a[5];
		x.m[0][6] = a[6];
		x.m[0][7] = a[7];
		x.m[0][8] = a[8];
		x.m[0][9] = a[9];
		x = x ^ (k - 9);
		LL sum = 0;
		for (int i = 0; i < 10; i++)
		{
			sum += x.m[0][i] * (9 - i) % n;
		}
		cout << sum%n << endl;
	}
	return 0;
}
