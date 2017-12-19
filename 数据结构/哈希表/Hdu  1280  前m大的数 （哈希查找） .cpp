//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1280
//��Ŀ���⣺���Ǹ���n,m,������n����,��n����������ӣ����ǰm�����
//����˼·���ù�ϣ����һһ��Ӧ�Ĺ�ϵ�������Ͳ���Ҫ����ֱ��һ�α����͵ó����

#include <iostream>  
#include <cstdio>
#include <string.h>
using namespace std;
const int maxn = 3000 + 10;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m;
	int a[maxn], b[maxn*4 + 10];
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				b[a[i] + a[j]]++;//��ϣ��һһ��Ӧ�Ĺ�ϵ������ ����Ҫ����ֱ�Ӳ���
			}
		}
		bool flag = false;
		for (int i = 10000; i > 0 && m > 0;) {
			if (b[i] && !flag) {
				printf("%d", i);
				flag = true;
				if (--b[i] == 0)i--;
				m--;
			}
			else if (b[i] && flag) {
				printf(" %d", i);
				if (--b[i] == 0)i--;
				m--;
			}
			else if (!b[i])i--;
		}
		printf("\n");
	}
	return 0;
}  