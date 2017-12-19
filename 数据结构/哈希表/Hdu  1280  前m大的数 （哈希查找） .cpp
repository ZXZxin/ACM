//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1280
//题目大意：就是给你n,m,并给你n个数,把n个数两两相加，求出前m大的数
//解题思路：用哈希表建立一一对应的关系，这样就不需要排序，直接一次遍历就得出结果

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
				b[a[i] + a[j]]++;//哈希表一一对应的关系，等下 不需要排序，直接查找
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