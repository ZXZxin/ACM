//׷�Ϸ�������ԽǷ�����
//�����Լ�ԭ�������  P59,P60
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
	for (int i = 1; i <= n - 1; i++)scanf("%lf", &c[i]);//���Խǵ��Ϸ�����
	for (int i = 2; i <= n; i++)scanf("%lf", &a[i]);//���Խǵ��·�����
	for (int i = 1; i <= n; i++)scanf("%lf", &b[i]);//���Խǵ��м�����
	for (int i = 1; i <= n; i++)scanf("%lf", &f[i]);//�ұߵľ���
	l[1] = b[1];
	for (int i = 1; i <= n - 1; i++) {//���õ�l�����u����
		u[i] = c[i] / l[i];
		l[i + 1] = b[i + 1] - a[i + 1] * u[i];
	}
	y[1] = f[1] / l[1];
	for (int i = 2; i <= n; i++)y[i] = (f[i] - a[i] * y[i - 1]) / l[i];//�������������y����
	x[n] = y[n];
	for (int i = n - 1; i >= 1; i--)x[i] = y[i] - u[i] * x[i + 1];//Ȼ�����x����
	for (int i = 1; i <= n; i++)printf("x[%d] = %6.4f\n", i, x[i]);
	return 0;
}
/*
����:
4
-1 -2 -2
-1 -2 -2
2 3 4 5
3 1 0 -5
*/
/*
������ʽ
2 -1          3
-1 3 -2       1
   -2 4 -2    0
      -2  5   -5
*/
/*
���:
x[1] = 2.0000
x[2] = 1.0000
x[3] = 0.0000
x[4] = -1.0000
*/