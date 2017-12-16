//追赶法求解三对角方程组
//解析以及原理见书上  P59,P60
#include <iostream>
#include <stdio.h>
const int maxn = 10 + 10;
using namespace std;

double a[maxn], b[maxn], c[maxn],f[maxn];
double l[maxn], u[maxn];
double x[maxn], y[maxn];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	scanf("%d", &n); 
	for (int i = 1; i <= n - 1; i++)scanf("%lf", &c[i]);//三对角的上方数组
	for (int i = 2; i <= n; i++)scanf("%lf", &a[i]);//三对角的下方数组
	for (int i = 1; i <= n; i++)scanf("%lf", &b[i]);//三对角的中间数组
	for (int i = 1; i <= n; i++)scanf("%lf", &f[i]);//右边的矩阵
	l[1] = b[1];
	for (int i = 1; i <= n - 1; i++) {//求解得到l数组和u数组
		u[i] = c[i] / l[i];
		l[i + 1] = b[i + 1] - a[i + 1] * u[i];
	}
	y[1] = f[1] / l[1];
	for (int i = 2; i <= n; i++)y[i] = (f[i] - a[i] * y[i - 1]) / l[i];//分两步，先求解y数组
	x[n] = y[n];
	for (int i = n - 1; i >= 1; i--)x[i] = y[i] - u[i] * x[i + 1];//然后求解x数组
	for (int i = 1; i <= n; i++)printf("x[%d] = %6.4f\n", i, x[i]);
	return 0;
}
/*
输入:
4
-1 -2 -2
-1 -2 -2
2 3 4 5
3 1 0 -5
*/
/*
矩阵形式
2 -1          3
-1 3 -2       1
   -2 4 -2    0
      -2  5   -5
*/
/*
输出:
x[1] = 2.0000
x[2] = 1.0000
x[3] = 0.0000
x[4] = -1.0000
*/