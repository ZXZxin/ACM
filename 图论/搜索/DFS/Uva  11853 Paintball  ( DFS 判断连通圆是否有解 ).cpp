//题目链接：https://vjudge.net/contest/169966#problem/V
//题目大意: 有一个正方形的 战场看，边长为1000，西南方向在坐标原点，战场上有n 个敌人，坐标x,y,攻击范围y
           //要你从西边界出发，东边界离开，求西边界和东边界上的坐标，坐标要尽量靠北，如果不能到达东边界输出IMPOSSIBLE
//解题思路: 按照 刘汝佳书上的思路，先判断有无解，从上边界开始DFS如果可以一直到达下边界，则相当于堵住了，无解
          //否则，也是从上边界开始，dfs和东西边界 相连的圆(如果没有就是1000)，找到最南边的圆的 与边界相交的那个点就 0k
          //主要还是DFS的运用
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

bool dfs(int u) {// 检查是否有解
	if (vis[u] == true)return false;
	vis[u] = true;
	if (y[u] <= r[u])return true;  //刚好碰到边界  以及  相切都可以 
	for (int i = 0; i < n; i++)if (isinterect(u,i) && dfs(i))return true;// if (&& dfs(i) && isinterect(u,i) )是错的，要先判断是否相交然后再dfs
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
			if (y[i] + r[i] >= W) {  //从上往下  DFS
				if (dfs(i)) { flag = false; break; }//如果能够从最上面 DFS 到最下面 则无解
			}
		}
		if (flag) printf("0.00 %.2lf 1000.00 %.2lf\n", Left,Right);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}