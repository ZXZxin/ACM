//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/O
//��Ŀ���⣺����һ���򵥵���������
//����˼·����Ҫ����Ϥ������洢�ڽӱ�ķ������ص㣩

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 100 + 10;
typedef struct {
	int point;
	int next_arc;
}Arc;

Arc arc[maxn];
int node[maxn];//�洢ÿ������ĵ�һ���ٽӵ�
int n, m;
int du[maxn];

void Topo() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (du[i] == 0)q.push(i);
	}
	int flag = false;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (flag)printf(" %d", now);
		else { printf("%d", now); flag = true; }
		for (int i = node[now]; i != -1; i = arc[i].next_arc) {
			if (--du[arc[i].point] == 0)q.push(arc[i].point);
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	int a, b;
	while(scanf("%d%d", &n, &m) != EOF && (n || m)) {
		memset(du, 0, sizeof(du));
		memset(node, -1, sizeof(node));
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			arc[i].next_arc = node[a];//�൱��ͷ�巨��������ÿ�����������
			node[a] = i;
			arc[i].point = b;
			du[b]++;
		}
		//        for(int i = 1; i <= n; i++){
		//            printf("�붥�� %d �����ӵĵ���:\n",i);
		//            for(int j = node[i]; j != -1; j = arc[j].next_arc)printf("%d ",arc[j].point);
		//            printf("\n");
		//        }
		Topo();
		printf("\n");
	}
	return 0;
}
