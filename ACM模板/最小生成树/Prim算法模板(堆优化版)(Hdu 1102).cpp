//Prim算法模板(堆优化版)
//题目链接 : http://acm.hdu.edu.cn/showproblem.php?pid=1102
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100 + 10;
const int INF = 1<<30;

struct Node{
    int v,w;
    Node (){}
    Node (int v,int w):v(v),w(w){}
    bool operator < (const Node&rhs ) const {
        return rhs.w < w;
    }
};

int n,d[maxn];
bool vis[maxn];
int Map[maxn][maxn];

void init(){
    for(int i = 0; i < maxn; i++)vis[i] = false;
    for(int i = 0; i < maxn; i++)d[i] = INF;
}

int Prim(int s){
    priority_queue<Node>q;
    q.push(Node(s,0));
    int ans = 0;
    while(!q.empty()){
        Node Now = q.top(); q.pop();
        int v = Now.v;
        if(vis[v]) continue;
        ans += Now.w;
        vis[v] = true;
        for(int i = 0; i < n; i++){
            int w2 = Map[v][i];
            if(!vis[i] && d[i] > w2){
                d[i] = w2;
                q.push(Node(i,d[i]));
            }
        }
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    int q,a,b;
    while(~scanf("%d",&n)){
        init();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d",&Map[i][j]);
            }
        }
        scanf("%d",&q);
        for(int i = 0; i < q; i++){
            scanf("%d%d",&a,&b);
            Map[a-1][b-1] = Map[b-1][a-1] = 0;

        }
        printf("%d\n",Prim(0));
    }
    return 0;
}
