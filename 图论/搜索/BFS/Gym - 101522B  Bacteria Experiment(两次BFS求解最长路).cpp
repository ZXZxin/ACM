//题目大意 : https://vjudge.net/contest/216411#problem/B
//题目大意 : 就是给你一个数n,并给你n个结点的生成树,每一个小时连着同一个公共点的两个点之间可以连起来
        // 问你要多少小时可以把这颗树连成一个完全图
//解题思路 : 主要就是求一条最长路,可以走2^hour个结点,两次BFS可以求的最长路,然后求解即可

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 5*1e5 + 10;
typedef long long LL;

struct Node{
    int v,w;
    Node(){}
    Node(int v,int w):v(v),w(w){}
};

vector<Node>G[maxn];
bool vis[maxn];
Node Now;

void BFS(int s){
    memset(vis,false,sizeof(vis));
    queue<Node>q;
    q.push(Node(s,0));
    vis[s] = true;
    while(!q.empty()){
        Now = q.front(); q.pop();
        for(int i = 0; i < G[Now.v].size(); i++){
            int v = G[Now.v][i].v;
            if(vis[v])continue;
            vis[v] = true;
            q.push(Node(v,Now.w+1));
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a,b;
    scanf("%d",&n);
    if(n == 2) {printf("0\n"); return 0;}
    for(int i = 0; i <= n; i++)G[i].clear();
    for(int i = 0; i < n-1; i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(Node(b,1));
        G[b].push_back(Node(a,1));
    }
    BFS(a);
    BFS(Now.v);
    LL ans[60];
    ans[1] = 2;
    for(int i = 2; i < 60; i++)ans[i] = ans[i-1]*2;
    int res = 1; //注意可能只有一个
    for(int i = 2; i < 60; i++){
        if(Now.w > ans[i-1] && Now.w <= ans[i]){
            res = i;
            break;
        }
    }
    printf("%d\n",res);
    return 0;
}
