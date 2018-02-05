//题目链接: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3270
//题目大意: 一个有v个顶点的完全图，找一条经过m条指定边的最短路径
//解题思路:当每条边仅经过一次时，路径最短
    /*若一棵树的奇点个数为0，则这棵树可以构成欧拉回路，若不为0，则必有走不到的边（每条边仅经过一次）。
    在一棵树中，设奇点个数为n，则走不到的边数为(n-2)/2 （n-2为除去起点和终点的奇点个数），
    这意味着，还需要走额外的(n-2)/2条边才能将这(n-2)/2条指定的但走不到的边走完。并且，这(n-2)/2条走不到的边是不共点的*/

//邻接表的解法:
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <algorithm>

const int maxn = 1000 + 10;
using namespace std;

struct edge{
    int v,next;
}edge[maxn*50];

int head[maxn];
int in[maxn];
bool vis[maxn];
int ans1,ans2;//分别代表连通块的数目和 每个连通块的奇点的数目
int n,m;
int cnt;

void add(int u,int v){
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void DFS(int u){
    ans2 += (in[u]&1); //if(in[u]%2 == 1)ans2 += 1;else ans2 += 0;
    for(int i = head[u]; i != -1; i = edge[i].next){
        if(!vis[edge[i].v]){
            vis[edge[i].v] = true;
            DFS(edge[i].v);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,u,v,kase = 0;
    while(scanf("%d%d%d",&n,&m,&T) && (m || n || T)){
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        /*for(int i = 1; i <= m; i++){
            scanf("%d%d",&u,&v);
            edge[i].v = v;
            edge[i].next = head[u];
            head[u] = i;
            edge[m+i].v = u;
            edge[m+i].next = head[v];
            head[v] = m+i;
            vis[u] = vis[v] = true;
        }*/
         cnt = 0;
         for(int i = 1; i <= m; i++){
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
            in[u]++,in[v]++;
        }
        int sum = 0;
        ans1 = 0;//连通块的数量
        for(int i = 1; i <= n; i++){
            if(head[i] != -1 && !vis[i]){
                ans1++;  //统计连通块的数量
                ans2 = 0;
                vis[i] = true;
                DFS(i);
                if(ans2 >= 2)sum += (ans2 - 2)/2;
            }
        }
        sum += m;
        if(ans1 >= 2)sum += (ans1 - 1);//连通连通块之间的线:连通块的数目减1
        printf("Case %d: %d\n",++kase,max(0,sum*T));
    }
    return 0;
}

//邻接矩阵的解法:(时间长一些)(这个较下面那个更容易理解)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

const int maxn = 1000 + 10;
using namespace std;
int G[maxn][maxn];
int in[maxn];
int ans1,ans2;//分别代表连通块的数目和 每个连通块的边数
int n,m;

void DFS(int u){
    for(int v = 1; v <= n; v++){
        if(G[u][v]){
            in[u]++;in[v]++;
            G[u][v] = G[v][u] = 0; //设置为已经访问
            ans2++;//每一个连通块如果是欧拉回路的情况下需要的边数(其实就是点数减1)
            DFS(v);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,u,v,kase = 0;
    while(scanf("%d%d%d",&n,&m,&T) && (m || n || T)){
        memset(G,0,sizeof(G));
        for(int i = 0; i < m; i++){
            scanf("%d%d",&u,&v);
            G[u][v] = G[v][u] = 1;
        }
        int sum = 0;
        ans1 = 0;//连通块的数量
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(G[i][j]){
                    ans1++;  //统计连通块的数量
                    memset(in,0,sizeof(in));//为了统计每一个连通块的度数
                    ans2 = 0;
                    DFS(i);
                    int ans3 = 0;
                    for(int k = 1; k <= n; k++)if(in[k]%2 == 1)ans3++;//统计奇点的数目
                    if(ans3 >= 2)sum += (ans2 + (ans3 - 2)/2);
                    else sum += (ans2 + (ans3/2));
                }
            }
        }
        if(ans1 >= 2)sum += (ans1 - 1);//连通连通块之间的线:连通块的数目减1
        printf("Case %d: %d\n",++kase,sum*T);
    }
    return 0;
}


//邻接矩阵的另一种方法:(简化)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

const int maxn = 1000 + 10;
using namespace std;
int G[maxn][maxn];
int in[maxn];
int n,m;

void DFS(int u){
    for(int v = 1; v <= n; v++){
        if(G[u][v]){
            in[u]++;in[v]++;
            G[u][v] = G[v][u] = 0; //设置为已经访问
            DFS(v);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,u,v,kase = 0;
    while(scanf("%d%d%d",&n,&m,&T) && (m || n || T)){
        memset(G,0,sizeof(G));
        for(int i = 0; i < m; i++){
            scanf("%d%d",&u,&v);
            G[u][v] = G[v][u] = 1;
        }
        int sum = 0;
        int ans1 = 0;//连通块的数量
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(G[i][j]){
                    ans1++;  //统计连通块的数量
                    memset(in,0,sizeof(in));
                    DFS(i);
                    int ans3 = 0;
                    for(int k = 1; k <= n; k++)if(in[k]%2 == 1)ans3++;//统计奇点的数目
                    if(ans3 >= 2)sum += (ans3 - 2)/2;
                }
            }
        }
        sum += m;
        if(ans1 >= 2)sum += (ans1 - 1);//连通连通块之间的线:连通块的数目减1
        printf("Case %d: %d\n",++kase,sum*T);
    }
    return 0;
}

