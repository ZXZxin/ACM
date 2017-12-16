//各种求解一元线性方程的数值解法总结：

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
//f(x) = x*x*x - 3*x - 1有三个实根，x1 = 1.8793 ,x2 = -0.34727,x3 = -1.53209
//下面采用六种不同的计算格式，求解f(x) = 0的根 x1 或 x2
double f1(double x) { return (3 * x + 1) / (x*x); }
double fd1(double x) { return (3 * x*x + 6 * x*x + 2 * x) / (x*x*x*x); }//f1的导数
double f2(double x) { return (x*x*x - 1) / 3; }
double fd2(double x) { return x*x; }//f2的导数
double f3(double x) { return pow(3 * x + 1, 1.0 / 3); }
double f4(double x) { return 1 / (x*x - 3); }
double fd4(double x) { return 2 * x / ((x*x - 2)*(x*x - 2)); }
double f5(double x) { return sqrt(3 + 1 / x); }
double f6(double x) { return x - (x*x*x - 3 * x - 1) / (3 * (x*x - 1)); }
//f7是书上弦截法的例题
double f7(double x) { return exp(-x) - x; }
double fd7(double x) { return -exp(-x) - 1; }
double eps = 1e-7;


int erFen(double x0, double x1) {
	int sum = 0;
	if (f1(x0) * f1(x1) < 0) {
		do {
			double mid = (x0 + x1) / 2;
			if (f1(mid)*f1(x0) < 0)x1 = mid;
			else x0 = mid;
			sum++;
			printf("x = %8.6f\n", x1);
		} while (fabs(x1 - x0) > eps);
	}
	return sum;
}

int Simple(double x0, double x1) {//简单迭代法
	double d = 0;
	int sum = 0;
	do {
		x1 = f2(x0);
		d = fabs(x1 - x0);
		x0 = x1;
		sum++;
		printf("x = %8.6f\n", x1);
	} while (d >= eps);
	return sum;
}

int SiTiFen(double x0, double x1) {//史蒂芬森加速算法
	double d = 0, y0 = 0, z0 = 0;
	int sum = 0;
	do{
		y0 = f4(x0);
		z0 = f4(y0);
		x1 = z0 - (z0 - y0)*(z0 - y0) / (z0 - 2 * y0 + x0);
	    d = fabs(x1 - x0);
		x0 = x1;
		sum++;
		printf("x = %8.6f\n", x1);
	} while (d >= eps);
	return sum;
}

int NiuDun(double x0, double x1) {//牛顿跌代法
	double d = 0;
	int sum = 0;
	do {
		x1 = x0 - f2(x0) / fd2(x0);
		d = fabs(x1 - x0);
		x0 = x1;
		sum++;
		printf("x = %8.6f\n", x1);
	} while (d >= eps);
	return sum;
}

int XiaShan(double x0,double x1){//牛顿下山法
	double d = 0;
	int sum = 0;
	do {
		if (fd2(x0) == 0) break; //倒数为0
		double t = 1.0;
		while (1) {
			x1 = x0 - (1.0 / t)*(f2(x0) / fd2(x0));
			if (fabs(f2(x1)) < fabs(f2(x0)))break;
			else {
				if (t == 1.0)t = t + 1;
				else t = t + 2;  //取1,1/2,1/4,1/8
			}
		}
		d = fabs(x1 - x0);
		sum++;
		x0 = x1;
		printf("x = %8.6f\n", x1);
	} while (d >= eps);
	return sum;
}

int XianJie(double x0, double x1, double x2) {//弦截法
	//答案：解：0.56714  (f7)
	int sum = 0;
	do {
		x2 = x1 - f7(x1) * (x1 - x0) / (f7(x1) - f7(x0));
		x0 = x1;
		x1 = x2;
		sum++;
		printf("x = %8.6f\n", x2);
	} while (fabs(x1 - x0) >= eps);
	return sum;
}

int main() {
	double x0 = 0,x1 = 0, x2 = 0;
	x0 = -0.5, x1 = -0.25;//选取二分的开始两个点
	printf("二分法收敛次数是 %d\n\n", erFen(x0, x1));
	x1 = 0, x0 = 0.5;
	printf("简单迭代法收敛次数是 %d\n\n", Simple(x0, x1));
	x1 = 0, x0 = 0.5;
	printf("史蒂芬森加速算法收敛次数是 %d\n\n", SiTiFen(x0, x1));
	x1 = 0, x0 = 0.5;
	printf("牛顿迭代法收敛次数是 %d\n\n", NiuDun(x0, x1));//牛顿法和下山法貌似没有算出正确答案
	x1 = 0, x0 = 0.5;
	printf("牛顿下山法收敛次数是 %d\n\n", XiaShan(x0, x1));
	x1 = 0.5, x0 = 0.6;
	printf("弦截法收敛次数是 %d\n\n", XianJie(x0, x1, x2));
	return 0;
}



