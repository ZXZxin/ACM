//题目链接：http://poj.org/problem?id=3253
//题目大意：给定一个木条，锯成input中要求的段数和每一段的长度，
          //每锯一次花费锯成被锯成两半的木条长度之和，求最小花费
//解题思路：二叉堆基础题


//（1）
#include <iostream>
#define maxn 20000+2

using namespace std;

typedef long long LL;
int a[maxn];
int n, min1;

void sort_heap(int m)
{
	int t;
	while (m * 2 <= n)
	{
		m *= 2;
		if (m + 1 <= n&&a[m] > a[m + 1])
			m++;
		if (a[m] < a[m / 2])
		{
			t = a[m];
			a[m] = a[m / 2];
			a[m / 2] = t;
		}
		else break;
	}
}

int main()
{
	LL sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n / 2; i > 0; i--)
		sort_heap(i);
	while (n > 1)
	{
		min1 = a[1];
		a[1] = a[n];
		n--;
		sort_heap(1);

		min1 += a[1];
		a[1] = min1;
		sort_heap(1);
		sum += min1;
	}
	cout << sum << endl;
	return 0;
}

//（2）
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long LL;

LL a[20010];
int m, n;

void heap(int m)
{
	int t;
	while (m * 2 <= n)//有子堆
	{
		m = m * 2;
		if (m < n && a[m] > a[m + 1]) // 较大的子堆
		{
			m++;
		}
		if (a[m] < a[m / 2]) //
		{
			t = a[m];
			a[m] = a[m / 2];
			a[m / 2] = t;
		}
		else
			break;
	}
}

void push_heap()
{
	int i = n;
	LL x = a[n];
	while (i > 1 && a[i / 2] > x)
	{
		a[i] = a[i / 2];
		i /= 2;
	}
	a[i] = x;
}

void pop_heap()
{
	LL x;
	//swap top.root
	x = a[1];
	a[1] = a[n];
	a[n] = x;

	n--;
	heap(1);
}

void make_heap()
{
	int i;
	for (i = n / 2; i > 0; i--)//从n/2构建即可
	{
		heap(i);
	}
}

void ace()
{
	int i;
	LL cur0, cur1, cur, sum;
	while (~scanf("%d", &n))
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%I64d", &a[i]);
		}
		make_heap();
		sum = 0;
		while (n != 1)
		{
			pop_heap();
			cur0 = a[n + 1];
			pop_heap();
			cur1 = a[n + 1];
			cur = cur0 + cur1;
			sum += cur;
			a[++n] = cur;
			push_heap();
		}
		printf("%I64d\n", sum);
	}
}

int main()
{
	ace();
	return 0;
}

//（3）
#include <iostream>
#include <cstdio>
#include <queue>

#define LL long long
using namespace std;

struct node
{
	LL m;
	bool operator < (const node &a)const
	{
		return m > a.m;
	}
};

int n;
int main()
{
	node t;
	node t1, t2;
	int i;
	LL cost;
	priority_queue <node> q;
	while (~scanf("%d", &n))
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &t.m);
			q.push(t);
		}

		cost = 0;
		while (!q.empty())
		{
			t1 = q.top();
			q.pop();
			if (q.empty())
				break;
			t2 = q.top();
			q.pop();

			t1.m += t2.m;
			cost += t1.m;
			if (q.empty())
				break;
			q.push(t1);
		}
		printf("%lld\n", cost);
	}
	return 0;
}

//（4）
#include <iostream>
#include <cstdio>
#include <queue>

#define LL long long
using namespace std;

struct cmp1
{
	bool operator ()(int &a, int &b)
	{
		return a > b;//最小值优先
	}
};
int n;
int main()
{
	int  t;
	int t1, t2;
	int i;
	LL cost;
	priority_queue<int, vector<int>, cmp1>q;//最小值优先
	while (~scanf("%d", &n))
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &t);
			q.push(t);
		}

		cost = 0;
		while (!q.empty())
		{
			t1 = q.top();
			q.pop();
			if (q.empty())
				break;
			t2 = q.top();
			q.pop();

			t1 += t2;
			cost += t1;
			if (q.empty())
				break;
			q.push(t1);
		}
		printf("%lld\n", cost);
	}
	return 0;
}

//（5）
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{
	int k;
	priority_queue<int, vector<int>, greater<int> >q;
	while (cin >> k)
	{
		int x;
		while (!q.empty())
			q.pop();
		for (int i = 0; i < k; i++)
		{
			cin >> x;
			q.push(x);
		}
		LL sum = 0;
		while (q.size() != 1)
		{
			int a = q.top(); q.pop();
			int b = q.top(); q.pop();
			sum += a + b;
			q.push(a + b);
		}
		cout << sum << endl;
	}
}
