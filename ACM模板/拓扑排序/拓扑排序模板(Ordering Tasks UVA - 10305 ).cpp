//拓扑排序的模板
//题目链接 : https://vjudge.net/contest/169966#problem/O

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int maxn = 100 + 10;

struct Edge{
    int v,next;
    Edge(){}
    Edge(int v,int next):v(v),next(next){}
}edge[maxn*2];

int n,m;
int head[maxn],indegree[maxn];
int cnt; //边的条数

void add(int u,int v){
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void BFS(){
    queue<int>q;
    for(int i = 1; i <= n ; i++)if(indegree[i] == 0)q.push(i);
    bool flag = true;
    while(!q.empty()){
        int now = q.front();q.pop();
        if(flag){printf("%d",now); flag = false;}
        else printf(" %d",now);
        for(int i = head[now]; i != -1; i = edge[i].next){
            if(--indegree[edge[i].v] == 0){
                q.push(edge[i].v);
            }
        }
    }
}

int main(){
    int a,b;
    while(~scanf("%d%d",&n,&m)&&(n || m)){
        memset(head,-1,sizeof(head));
        memset(indegree,0,sizeof(indegree));
        cnt = 0;
        for(int i = 0; i < m; i++){
            scanf("%d%d",&a,&b);
            indegree[b]++;
            add(a,b);
        }
//        for(int i = 1; i <= n; i++){
//            printf("%d :", i);
//            for(int j = head[i]; j != -1; j = edge[j].next)printf(" %d",edge[j].v);
//            printf("\n");
//        }
        BFS();
        printf("\n");
    }
    return 0;
}
