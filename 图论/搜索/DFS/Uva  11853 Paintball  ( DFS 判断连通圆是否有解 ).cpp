//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/V
//��Ŀ����: ��һ�������ε� ս�������߳�Ϊ1000�����Ϸ���������ԭ�㣬ս������n �����ˣ�����x,y,������Χy
           //Ҫ������߽���������߽��뿪�������߽�Ͷ��߽��ϵ����꣬����Ҫ����������������ܵ��ﶫ�߽����IMPOSSIBLE
//����˼·: ���� ��������ϵ�˼·�����ж����޽⣬���ϱ߽翪ʼDFS�������һֱ�����±߽磬���൱�ڶ�ס�ˣ��޽�
          //����Ҳ�Ǵ��ϱ߽翪ʼ��dfs�Ͷ����߽� ������Բ(���û�о���1000)���ҵ����ϱߵ�Բ�� ��߽��ཻ���Ǹ���� 0k
          //��Ҫ����DFS������
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

const int maxn = 1000 + 10;
const double W = 1000.0;
using namespace std;

double x[maxn], y[maxn], r[maxn],Left,Right;
bool vis[maxn];
int n;

bool isinterect(int u, int v) {
	return sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v])) <= r[u] + r[v];
}

void check_circle(int u) {
	if (x[u] <= r[u])Left = min(Left, y[u] - sqrt(r[u] * r[u] - x[u] * x[u]));
	if (x[u] + r[u] >= W)Right = min(Right, y[u] - sqrt(r[u] * r[u] - (W-x[u]) * (W-x[u])));
}

bool dfs(int u) {// ����Ƿ��н�
	if (vis[u] == true)return false;
	vis[u] = true;
	if (y[u] <= r[u])return true;  //�պ������߽�  �Լ�  ���ж����� 
	for (int i = 0; i < n; i++)if (isinterect(u,i) && dfs(i))return true;// if (&& dfs(i) && isinterect(u,i) )�Ǵ�ģ�Ҫ���ж��Ƿ��ཻȻ����dfs
	check_circle(u);
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		memset(vis, false, sizeof(vis));
		Left = Right = W;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		}
		for (int i = 0; i < n; i++) {
			if (y[i] + r[i] >= W) {  //��������  DFS
				if (dfs(i)) { flag = false; break; }//����ܹ��������� DFS �������� ���޽�
			}
		}
		if (flag) printf("0.00 %.2lf 1000.00 %.2lf\n", Left,Right);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}