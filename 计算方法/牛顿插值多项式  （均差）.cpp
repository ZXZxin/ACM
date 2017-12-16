//ţ�ٲ�ֵ����ʽ����ֵ����
//��ʽ�Լ����ͼ����� P100,P101
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100 + 10;
double x[maxn], y[maxn], F[maxn][maxn],X;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%lf", &x[i]);
	for (int i = 0; i < n; i++)scanf("%lf", &y[i]);
	for (int i = 0; i < n; i++)F[i][0] = y[i];//��ά����ĵ�һ��
	for (int j = 1; j < n; j++) {//�����Ĺ�ʽ
		for (int i = j; i < n; i++) {
			F[i][j] = (F[i][j - 1] - F[i - 1][j - 1]) / (x[i] - x[i - j]);
		}
	}
	printf("���������:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%6.4f", F[i][j]);
		}
		printf("\n");
	}
	while (scanf("%lf", &X) != EOF) {//����Ҫ���x��Ӧ�ĺ���ֵ
		double sum = 0;
		for (int i = 0; i < n; i++) {//����ֵ
			double temp = F[i][i];
			for (int j = 0; j < i; j++)temp *= (X - x[j]);
			sum += temp;
		}
		printf("\n%8.6f\n", sum);
	}
	return 0;
}
/*
����:
5
0.4 0.55 0.65 0.8 0.9
0.4175 0.57815 0.69657 0.88811 1.02652
0.5
0.85
1.05
*/
/*
���:
���������:
0.41750.00000.00000.00000.0000
0.57821.07100.00000.00000.0000
0.69661.18420.45280.00000.0000
0.88811.27690.3709-0.20470.0000
1.02651.38410.42870.16500.7392

0.522016

0.956050

1.258229
*/
