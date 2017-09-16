//题目链接：http://hihocoder.com/problemset/problem/1062
//题目大意：见链接
//解体思路：（1）找两个人的全部祖先，取交集
          //（2）回溯，标记一个人的祖先，顺着另一个人的父亲找，找到有标记的第一个即可

#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
using namespace std;

map<string, string >mm;
set<string>s;

int main()
{
	int n, m;
	string name1, name2;
	string a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2;
		mm[name2] = name1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		s.clear();
		while (mm.count(a))
		{
			s.insert(a);
			a = mm[a];
		}
		s.insert(a);
		if (s.find(b) != s.end())
		{
			cout << b << endl;
			continue;
		}
		bool flag = false;
		while (mm.count(b))
		{
			b = mm[b];
			if (s.find(b) != s.end())
			{
				cout << b << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "-1" << endl;
	}
	return 0;
}

//法2：
#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

map<string, string> sontofar;
map<string, int> vis;

void check(string tmp1, string tmp2)
{
	vis.clear();
	string ind = tmp1;

	while (!ind.empty())
	{
		vis[ind] = 1;
		ind = sontofar[ind];
	}

	ind = tmp2;
	while (!ind.empty() && vis[ind] == 0)
		ind = sontofar[ind];

	if (ind.empty())
		cout << "-1" << endl;
	else
		cout << ind << endl;
}

int main()
{
	//freopen("input.txt","r",stdin);
	int t, p = 0;
	string tmp1, tmp2;

	cin >> t;
	while (t--)
	{
		cin >> tmp1 >> tmp2;
		sontofar[tmp2] = tmp1;
	}

	cin >> t;
	while (t--)
	{
		cin >> tmp1 >> tmp2;
		check(tmp1, tmp2);
	}
	return 0;
}

