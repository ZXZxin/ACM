//题目连接；http://poj.org/problem?id=1611
//题目大意：病毒传染，可以通过一些社团接触
          //给出一些社团，问有多少人被感染
//解题思路：并查集找出公共祖先，加入集合,然后找出和0在同一个集合的元素个数，顺便用ranks记录秩以优化



#include <iostream>
#define maxn 30001
using namespace std;

int pa[maxn];
int ranks[maxn];

int Find(int v){
	if (pa[v] == v)return v;
	return pa[v] = Find(pa[v]);
}

void Union(int x, int y){
	int fx = Find(x);
	int fy = Find(y);
	if (fx == fy)return;
	if (ranks[fx] < ranks[fy])//fy的高度大于fx
		pa[fx] = fy;  //按秩合并的原理是使得树的高度尽量的小
	else{
		pa[fy] = fx;
		if (ranks[fx] == ranks[fy])
			ranks[fy]++;
	}
}

int main(){
	int n, m, k, x, y;
	while (cin >> n >> m && (n || m)){
		int sum = 1;
		for (int i = 0; i < n; i++){//初始化
			pa[i] = i;
			ranks[i] = 0;
		}
		for (int i = 0; i < m; i++){
			cin>>k;
			if (k >= 1)cin >> x;
			for (int j = 1; j < k; j++){
				cin >> y;
				Union(x, y);//合并集合
			}
		}
		for (int i = 1; i < n; i++){
			if (Find(0) == Find(i))//和0在同一个集合的元素
				sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
