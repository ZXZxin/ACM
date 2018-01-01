//  ��΢�ַ��̵���ֵ�ⷨ
//  �Ľ���ŷ����ʽ������Ľ��Ϳ� ��ʦ�ٰ���㷽�� P153 - P156
//  y[i + 1]' = yi + h * f(xi,yi);//Ԥ�⣨ŷ����ʽ��
//  y[i + 1] = yi + h * (f(xi,yi) + f(x[i + 1],y[i+1]'))// �����ι�ʽУ����

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

double f(double x, double y) {//P158����
	return y - 2 * x / y;
}

int main() {
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double x0, y0, xn, x1, y1;
	//double yp, yc;
	int n;
	scanf("%lf%lf%lf%d", &x0, &y0, &xn, &n);//����������ߵ�x0,y0,�������ұߵ�xn,�Լ�������
	double h = (xn - x0) / n;  //�󲽳�
	for (int i = 1; i <= n; i++) {
		x1 = x0 + h; //�����һ����� x ֵ
		//yp = y0 + h * f(x0, y0);
		//yc = y0 + h * f(x1, yp);
		//y1 = (yp + yc) / 2;
		y1 = y0 + h / 2 * (f(x0, y0) + f(x1,y0 + h * f(x0, y0)));
		printf("x[%d] = 1%8.6f   y[x[%d]] = %8.6f\n",i,x1,i, y1);
		x0 = x1;
		y0 = y1;
	}
	return 0;
}

/*
���룺
0 1 1 10
*/
/*
���:
x[1] = 10.100000   y[x[1]] = 1.095909
x[2] = 10.200000   y[x[2]] = 1.184097
x[3] = 10.300000   y[x[3]] = 1.266201
x[4] = 10.400000   y[x[4]] = 1.343360
x[5] = 10.500000   y[x[5]] = 1.416402
x[6] = 10.600000   y[x[6]] = 1.485956
x[7] = 10.700000   y[x[7]] = 1.552514
x[8] = 10.800000   y[x[8]] = 1.616475
x[9] = 10.900000   y[x[9]] = 1.678166
x[10] = 11.000000   y[x[10]] = 1.737867
*/