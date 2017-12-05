//题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=5438
//题目大意：给你一个无向图，每个顶点有权值，现在要删除所有度为0或1的点，然后求连通分量中有奇数个节点的节点的权值和（团）
//解题思路:先建图，然后深搜度为0或1的点，并删除，然后统计即可

//重点：通过此题注意（1）用scanf()输入的时候一定要注意格式
                //（2）图的顶点的序号和for(int i = 0; ..) AND for(int i =1; ..)是不同的，和序号有关
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string.h>

typedef long long LL;
using namespace std;
const int maxn = 1000000;

struct node{
    int u,v;
    int next;
}Edge[maxn];

int head[maxn];
int in[maxn];
bool vis[maxn];
LL val[maxn];
int sum[maxn];
LL summ[maxn];//记录每个团的总权值
int n,m,cnt;

void add(int u,int v){
    Edge[cnt].u = u;//相当于每个顶点
    Edge[cnt].v = v;//相当于邻接点
    Edge[cnt].next = head[u];//每个边表头插建表
    head[u] = cnt++;
}

void DFS(int u){
    vis[u] = true;
    for(int i = head[u]; i != -1; i = Edge[i].next){
        int v = Edge[i].v;
        if(!vis[v]){
            if(--in[v] <= 1)DFS(v);
        }
    }
}

void DFSS(int u){
    vis[u] = true;
    sum[u] = 1;
    summ[u] = val[u];
    for(int i = head[u]; i != -1; i = Edge[i].next){
        int v = Edge[i].v;
        if(!vis[v]){
            DFSS(v);
            sum[u] += sum[v];
            summ[u] += summ[v];

        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T; LL u,v;
    scanf("%d",&T);
    while(T--){
        memset(in,0,sizeof(in));
        memset(val,0,sizeof(val));
        memset(vis,false,sizeof(vis));
        memset(head,-1,sizeof(head));
        memset(sum,0,sizeof(sum));
        memset(summ,0,sizeof(summ));
        cnt = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)scanf("%lld",&val[i]);
        for(int i = 1; i <= m; i++){
            scanf("%lld%lld",&u,&v);
            in[u]++;
            in[v]++;//无向图
            add(u,v);
            add(v,u);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                if(in[i] <= 1)DFS(i);
            }
        }
        LL ans = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                DFSS(i);
                if(sum[i] % 2 == 1)ans += summ[i];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

