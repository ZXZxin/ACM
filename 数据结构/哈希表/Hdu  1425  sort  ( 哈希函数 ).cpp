//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1425
//��Ŀ���⣺���Ǹ���n������Ҫ����ǰm�����
//����˼·�������ι�ϣ���ֱ�ȡ��Ӧ�ĵ�ַ(��¼�Ƿ����)

#include <iostream>  
#include <cstdio>
#include <math.h>
#include <string.h>
#include <string>
using namespace std;
const int maxn = 1000000 + 10;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m;
	int a[maxn],b[500000],c[500000];
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) {
			if (a[i] >= 0)b[a[i]]++;
			else c[abs(a[i])]--;
		}
		bool flag = false;
		for (int i = 500000; i >= 0 && m > 0; i--) {
			if (b[i] <= 0)  continue; 
			else if (!flag && b[i] > 0) { printf("%d", i); flag = true; }
			else if (flag && b[i] > 0)  printf(" %d", i);
			m--;
		}
		for (int i = 0; i <= 500000 && m > 0; i++) {
			if (c[i] >= 0) continue;
			if (!flag && c[i] < 0)  printf("%d", -i);
			else if (flag && c[i] < 0) printf(" %d", -i);
			m--;
		}
		printf("\n");
	}
	return 0;
}  