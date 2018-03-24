//��Ŀ���� : https://vjudge.net/contest/216411#problem/B
//��Ŀ���� : ���Ǹ���һ����n,������n������������,ÿһ��Сʱ����ͬһ���������������֮�����������
        // ����Ҫ����Сʱ���԰����������һ����ȫͼ
//����˼· : ��Ҫ������һ���·,������2^hour�����,����BFS��������·,Ȼ����⼴��

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
    int res = 1; //ע�����ֻ��һ��
    for(int i = 2; i < 60; i++){
        if(Now.w > ans[i-1] && Now.w <= ans[i]){
            res = i;
            break;
        }
    }
    printf("%d\n",res);
    return 0;
}
