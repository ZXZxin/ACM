//题目连接:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=995
//题目大意:给你n个珠子，一个珠子分为两半有两种颜色，用1到50来表示50种不同的颜色。把这些珠子串起来
          //两个紧挨着的珠子要满足一个条件就是接触的那部分颜色要相同
//解题思路：也是一个无向欧拉回路的应用以及路径的输出，还有就是这个题目可以允许重边
         //也就是g[i][j]的值不一定只是为1，然后从一个点出发，找到和他相连的点，然后删除这条无向边，所以是g[u][v]--;g[v][u]--
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
struct node{
    int u,v;
    node(){}
    node(int u,int v):u(u),v(v){}
};
const int maxn = 1000 + 10;
using namespace std;
int G[maxn][maxn],in[maxn];
bool vis[maxn];
stack<node>s;

void dfs(int u){  //判断是否连通
    vis[u] = 1;
    for(int i = 1; i <= 50; i++){
        if(!vis[i] && G[u][i]) {
            dfs(i);
        }
    }
}

void euler(int u){  // 求解路径
    for(int i = 1; i <= 50; i++){
        if(G[u][i]) {
            G[u][i]--;G[i][u]--;
            euler(i);
            s.push(node(u,i));
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,u,v;
    scanf("%d",&T);
    int kase = 0;
    while(T--){
        memset(vis,1,sizeof(vis));
        memset(G,0,sizeof(G));
        memset(in,0,sizeof(in));
        while(!s.empty())s.pop();
        bool flag = true;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d %d",&u,&v);
            G[u][v]++; G[v][u]++;
            in[v]++;in[u]++;
            vis[u] = vis[v] = 0;
        }
        for(int i = 1; i <= 50; i++)if(in[i]%2 != 0){
            flag = false;
            break;
        }
        dfs(u);
        for(int i = 1; i <= 50; i++)if(!vis[i]){
            flag = false;
            break;
        }
        printf("Case #%d\n",++kase);
        if(!flag){
            printf("some beads may be lost\n");
            if(T != 0)printf("\n");
            continue;
        }
        euler(u);
        while(!s.empty()){
            printf("%d %d\n",(s.top()).u,(s.top()).v);
            s.pop();
        }
        if(T != 0)printf("\n");
    }
    return 0;
}
