//��Ŀ���ӣ�https://vjudge.net/contest/169967#problem/B
//��Ŀ����: ���Ǹ���һ����������,ÿһ�����һ��01����,����Ҷ�ӵ�ֵ,Ҫ��Ӹ��ڵ㿪ʼ��,����һ�����а����Ǹ�����,0����,1����,����󵽴�Ҷ�ӵ�ֵ
//����˼·: ��һ��ѧ���˺ܶ������ ֪ʶ����ЩҲ�ǻ�����֪ʶ���粻֪�������ַ��ǲ���"%1d"�������֣��Լ��������Ķ�Ӧ�±�

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string>

const int maxn = 1<<10;
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, kase = 0;
	int a[maxn],dep[maxn],leaf[maxn], ans[maxn];//dep����� i ��� x��� ��leaf����� Ҷ�ӵ�����ans�����
	while (scanf("%d", &n) != EOF && n != 0) {
		getchar();//ֻҪ������ char,���� char*,��Ҫgetchar()һ��
		for (int i = 0; i < n; i++) {
			getchar();
			scanf("%d", &dep[i]);
			getchar();
		}
		for(int i = pow(2,n); i <= pow(2,n+1) - 1; i++)scanf("%1d",&leaf[i]);//n + 1���Ҷ��
		scanf("%d", &m);
		int k = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= n; j++)scanf("%1d",&a[j]);//ע��ֵ //�����������ÿһ�εĲ�������
			int x = 1;
			for (int j = 0; j < n; j++) {
				if (a[dep[j]] == 0)x *= 2;
				else if(a[dep[j]] == 1)x = x * 2 + 1;
			}
			ans[k++] = leaf[x];
		}
		printf("S-Tree #%d:\n",++kase);
		for (int i = 0; i < k; i++)printf("%d", ans[i]);
		printf("\n\n");
	}
	return 0;
}
