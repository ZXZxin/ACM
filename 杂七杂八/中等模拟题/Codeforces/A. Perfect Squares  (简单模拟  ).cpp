//题目链接：http://codeforces.com/contest/914/problem/A
//题目大意: 就是要你找出  一组数 中不是 Perfect Squares 数中的最大数 ，Perfect Squares数就是存在 y ,使得 这个数 = y*y;
//解题思路: 直接模拟即可，注意 负数 的情况以及题目的范围 

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn = 1000 + 10;
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	int a[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	int maxx = -1000010;
	for (int i = 0; i < n; i++) {
		if ((a[i] >= 0 && (int)sqrt(a[i]) * (int)sqrt(a[i]) != a[i]) || (a[i] < 0)) {
			if (a[i] > maxx) {
				maxx = a[i];
			}
		}
	}
	printf("%d\n", maxx);
	return 0;
}