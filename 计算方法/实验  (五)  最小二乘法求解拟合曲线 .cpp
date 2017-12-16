//��С���˷�����������
//�����̿�����P116(��ʦ�ٰ�)
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const int maxn = 100 + 10;

double x[maxn], y[maxn];//���ݵ�
double a[maxn][maxn], b[maxn];//��˹��Ԫ�еľ���
double ans[maxn];//Ҫ����a����
double R[maxn];

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d", &n);//���ݵ�����
	for (int i = 1; i <= n; i++)scanf("%lf", &x[i]);
	for (int i = 1; i <= n; i++)scanf("%lf", &y[i]);
	scanf("%d", &m);//����ʽ��ϵĴ���  : ���� 1 ���� ֱ�����  a0 + a1*x 
	a[0][0] = n;
	for (int i = 1; i <= m; i++) {//������������һ��
		double sum = 0;
		for (int j = 1; j <= n; j++)sum += pow(x[j], i);
		a[0][i] = sum;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= m; j++) {
			double sum = 0;
			for (int k = 1; k <= n; k++)sum += pow(x[k], j + i);
			a[i][j] = sum;
		}
	}
	for (int i = 0; i <= m; i++) {
		double sum = 0;
		for (int j = 1; j <= n; j++)sum += y[j] * pow(x[j], i);
		b[i] = sum;
	}
	int k;//��˹��Ԫ���
	for (k = 0; k < m; k++) {//m - 1����Ԫ
		for (int i = k + 1; i <= m; i++) {
			for (int j = k + 1; j <= m; j++) ///ע��һ��Ҫ�� K + 1��ʼ
				a[i][j] = a[i][j] - a[k][j] * a[i][k] / a[k][k];
			b[i] = b[i] - b[k] * a[i][k] / a[k][k];
		}
	}
	for (int i = m; i >= 0; i--) {//���ans���飨����
		double sum = 0;
		for (int j = i + 1; j <= m; j++) sum = sum + a[i][j] * ans[j];
		ans[i] = (b[i] - sum) / a[i][i];
	}
	printf("a��������:\n");
	for (int i = 0; i <= m; i++) printf("a[%d] = %6.4f\n", i, ans[i]);
	for (int i = 1; i <= n; i++) {
		double sum = ans[0];
		for (int j = 1; j <= m; j++)sum += ans[j]*pow(x[i], j);
		R[i] = sum - y[i];
	}
	printf("\n����R����Ϊ:\n");
	for (int i = 1; i <= n; i++)printf("R[%d] = %6.4f\n",i, R[i]);
	return 0;
}
/*
12
0 5 10 15 20 25 30 35 40 45 50 55
0 1.27 2.16 2.86 3.44 3.87 4.15 4.37 4.51 4.58 4.02 4.64
3
*/
/*
 4
 1.36 1.73 1.95 2.28
 14.094 16.844 18.475 20.963
 1
 */