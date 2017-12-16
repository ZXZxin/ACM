//�������һԪ���Է��̵���ֵ�ⷨ�ܽ᣺

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
//f(x) = x*x*x - 3*x - 1������ʵ����x1 = 1.8793 ,x2 = -0.34727,x3 = -1.53209
//����������ֲ�ͬ�ļ����ʽ�����f(x) = 0�ĸ� x1 �� x2
double f1(double x) { return (3 * x + 1) / (x*x); }
double fd1(double x) { return (3 * x*x + 6 * x*x + 2 * x) / (x*x*x*x); }//f1�ĵ���
double f2(double x) { return (x*x*x - 1) / 3; }
double fd2(double x) { return x*x; }//f2�ĵ���
double f3(double x) { return pow(3 * x + 1, 1.0 / 3); }
double f4(double x) { return 1 / (x*x - 3); }
double fd4(double x) { return 2 * x / ((x*x - 2)*(x*x - 2)); }
double f5(double x) { return sqrt(3 + 1 / x); }
double f6(double x) { return x - (x*x*x - 3 * x - 1) / (3 * (x*x - 1)); }
//f7�������ҽط�������
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

int Simple(double x0, double x1) {//�򵥵�����
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

int SiTiFen(double x0, double x1) {//ʷ�ٷ�ɭ�����㷨
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

int NiuDun(double x0, double x1) {//ţ�ٵ�����
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

int XiaShan(double x0,double x1){//ţ����ɽ��
	double d = 0;
	int sum = 0;
	do {
		if (fd2(x0) == 0) break; //����Ϊ0
		double t = 1.0;
		while (1) {
			x1 = x0 - (1.0 / t)*(f2(x0) / fd2(x0));
			if (fabs(f2(x1)) < fabs(f2(x0)))break;
			else {
				if (t == 1.0)t = t + 1;
				else t = t + 2;  //ȡ1,1/2,1/4,1/8
			}
		}
		d = fabs(x1 - x0);
		sum++;
		x0 = x1;
		printf("x = %8.6f\n", x1);
	} while (d >= eps);
	return sum;
}

int XianJie(double x0, double x1, double x2) {//�ҽط�
	//�𰸣��⣺0.56714  (f7)
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
	x0 = -0.5, x1 = -0.25;//ѡȡ���ֵĿ�ʼ������
	printf("���ַ����������� %d\n\n", erFen(x0, x1));
	x1 = 0, x0 = 0.5;
	printf("�򵥵��������������� %d\n\n", Simple(x0, x1));
	x1 = 0, x0 = 0.5;
	printf("ʷ�ٷ�ɭ�����㷨���������� %d\n\n", SiTiFen(x0, x1));
	x1 = 0, x0 = 0.5;
	printf("ţ�ٵ��������������� %d\n\n", NiuDun(x0, x1));//ţ�ٷ�����ɽ��ò��û�������ȷ��
	x1 = 0, x0 = 0.5;
	printf("ţ����ɽ������������ %d\n\n", XiaShan(x0, x1));
	x1 = 0.5, x0 = 0.6;
	printf("�ҽط����������� %d\n\n", XianJie(x0, x1, x2));
	return 0;
}



