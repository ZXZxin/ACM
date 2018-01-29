//题目链接：http://codeforces.com/contest/914/problem/B
//题目大意: 就是Conan 和 Agasa 一起玩一个纸牌游戏， 每个人每个回合可以拿走一张牌，拿走这张牌的同时
            //比这张牌小的牌也会被自动拿走，当哪个人的回合没牌的时候，这个人就输了，问在每个人的最好的情况下谁会赢
//解题思路: 一开始想的比较简单，只想了最大的那个数，后来发现，可以选择其他的数，然后举几个例子发现，只要某个数的个数是奇数，第一个取的人都会赢

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn = 100000 + 10;
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	int a[maxn],b[maxn];
	memset(b, 0, sizeof(b));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	bool flag = true;
	int maxx = a[0];
	for (int i = 0; i < n; i++)if (a[i] > maxx)maxx = a[i];
	for (int i = 0; i < n; i++) b[a[i]]++;
	for (int i = 0; i <= maxx; i++)if (b[i] % 2 == 1) {
		flag = false; break;
	}
	if (!flag)printf("Conan\n");
	else printf("Agasa\n");
	return 0;
}