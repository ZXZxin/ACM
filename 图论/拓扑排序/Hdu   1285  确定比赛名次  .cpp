//题目链接：http://acm.split.hdu.edu.cn/status.php
//题目大意：给定谁赢了谁，求出排名，按编号小的在前面
//解题思路：拓扑排序，使用优先队列

#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#define maxn 500+10
#define INF 1000000000

using namespace std;
int graph[maxn][maxn];
int indegree[maxn];
int n,m;

void topo(){
    priority_queue<int,vector<int>,greater<int> >q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    bool first=1;
    while(!q.empty()){
        int now = q.top();
        q.pop();
        if(first){cout<<now;first=0;}
        else cout<<" "<<now;
        for(int i=1;i<=n;i++){
            if(graph[now][i]){
               indegree[i]--;
               if(indegree[i]==0){
               q.push(i);
            }
        }
     }
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    while(cin>>n>>m){
        memset(graph,0,sizeof(graph));
        memset(indegree,0,sizeof(indegree));
        for(int i=1;i<=m;i++){
          int u,v;
          cin>>u>>v;
          if(!graph[u][v]){
           graph[u][v]=1;
           indegree[v]++;
          }
        }
        topo();
        cout<<endl;
    }
    return 0;
}



