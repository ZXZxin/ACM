//题目链接：http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1287
//题目大意：就是给你n个数，要你去除重复的数，然后排序输出
//解题思路：利用取余的散列函数 h(key) = key%Mod,然后利用拉链法的去除冲突的方法，如果有则不插入

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
const int maxn = 1007 + 10;
const int Mod = 1007;

struct node {
	int data;
	struct node * next;
};

struct HashNode{//哈希表的结构
	node *first;
}HashNode[maxn];
int num[maxn];//用来存储元素

int main() {
	//freopen("in.txt", "r", stdin);
	int n,x;
	while (scanf("%d", &n) != EOF)  {
		int k = 0;
		for (int i = 0; i < maxn; i++) {
			HashNode[i].first = NULL;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			int ans = x % Mod;
			bool flag1 = false;
			bool flag2 = false;
			if (HashNode[ans].first == NULL) {
				node *q = new node();
				q->data = x;
				HashNode[ans].first = q;
				HashNode[ans].first->next = NULL;
				num[k++] = x;
				flag2 = true;
			}
			else {
				node *pCur = HashNode[ans].first;
				while (pCur != NULL) {
					if (pCur->data == x) {
						flag1 = true;
						break;
					}
					pCur = pCur->next;
				}
			}
			if (!flag1 && !flag2) {
				node *q = new node(), *pTemp = HashNode[ans].first;
				while (pTemp->next)pTemp = pTemp->next;
				pTemp->next = q;
				q->data = x;
				q->next = NULL;
				num[k++] = x;
			}
		}
		sort(num, num + k);
		printf("%d\n", k);
		for (int i = 0; i < k - 1; i++)printf("%d ",num[i]);
		printf("%d\n", num[k - 1]);
	}
	return 0;
}  