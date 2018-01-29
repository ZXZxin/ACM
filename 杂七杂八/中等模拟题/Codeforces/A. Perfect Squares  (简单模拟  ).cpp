//��Ŀ���ӣ�http://codeforces.com/contest/914/problem/A
//��Ŀ����: ����Ҫ���ҳ�  һ���� �в��� Perfect Squares ���е������ ��Perfect Squares�����Ǵ��� y ,ʹ�� ����� = y*y;
//����˼·: ֱ��ģ�⼴�ɣ�ע�� ���� ������Լ���Ŀ�ķ�Χ 

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