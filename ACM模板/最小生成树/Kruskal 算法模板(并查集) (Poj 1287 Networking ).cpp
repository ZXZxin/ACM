//题目链接 : http://poj.org/problem?id=1287

//kruskal模板
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 1e5 + 10;

int Fa[maxn],Rank[maxn];

void init(){
    for(int i = 0; i <= maxn; i++)Fa[i] = i;
    for(int i = 0; i <= maxn; i++)Rank[i] = 1;
}

int Find(int v){
    return Fa[v] == v ? v : Fa[v] = Find(Fa[v]);
}

void Union(int x, int y){
	int fx = Find(x);
	int fy = Find(y);
	if (fx == fy)return;
	if (Rank[fx] < Rank[fy])
        Fa[fx] = fy;
	else{
		Fa[fy] = fx;
		if (Rank[fx] == Rank[fy])Rank[fy]++;
	}
}

struct Edge{
    int u,v,w;
    Edge(){}
    Edge(int u,int v,int w):u(u),v(v),w(w){}
}edge[maxn*2];


int cmp(const void *a,const void *b){
    Edge *aa = (Edge*)a;
    Edge *bb = (Edge*)b;
    return aa->w > bb->w ? 1 : -1; //降序
}

int krusal(int n,int m){
    qsort(edge,m,sizeof(edge[0]),cmp);
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        if(Find(u) != Find(v)){
            Union(u,v);
            cnt++;
            ans += edge[i].w;
        }
        if(cnt == n-1)break;
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    while(~scanf("%d",&n)&&n){
        scanf("%d",&m);
        init();
        for(int i = 0; i < m; i++) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w); //注意这题有重边但是没事
        printf("%d\n",krusal(n,m));
    }
    return 0;
}




