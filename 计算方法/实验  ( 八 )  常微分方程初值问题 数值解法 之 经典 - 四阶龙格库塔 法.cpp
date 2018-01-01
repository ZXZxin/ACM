//经典的四阶龙格 - 库塔 法 求解常微分方程的数值解
//算法的具体解释 等件  刘师少版计算方法 P159 - P163

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

double f(double x, double y) {// P162 的 例题
	return 2 * x * y;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double x0, y0, xn,x1,y1;
	double k1, k2, k3, k4;//四个中间的斜率
	int n;
	scanf("%lf%lf%lf%d", &x0, &y0, &xn, &n);//输入左边区间的  x0 ,y0,以及右边区间的 xn值，以及分的区间的个数
	double h = (xn - x0) / n;  //步长
	for (int i = 1; i <= n; i++) {
		x1 = x0 + h;
		k1 = f(x0, y0);
		k2 = f(x0 + h / 2, y0 + h * k1 / 2);
		k3 = f(x0 + h / 2, y0 + h * k2 / 2);
		k4 = f(x1, y0 + h * k3);
		y1 = h * (k1 + 2 * k2 + 2 * k3 + k4)/6 + y0;
		printf("x[%d] = %8.6f  y[%d] = %8.6f\n", i, x1, i, y1);
		x0 = x1, y0 = y1;
	}
	return 0;
}
/*
输入:
0 1 1 5
*/
/*
输出:
x[1] = 0.200000  y[1] = 1.040811
x[2] = 0.400000  y[2] = 1.173510
x[3] = 0.600000  y[3] = 1.433321
x[4] = 0.800000  y[4] = 1.896441
x[5] = 1.000000  y[5] = 2.718107
*/