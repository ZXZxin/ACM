//��Ŀ���� : https://vjudge.net/contest/216415#problem/I
//��Ŀ���� : ���Ǹ���һЩ��(ÿ��20λ)����֮������໥�ƶ�,ǰ������������Common����,����0-9��������ȥmin
            //�������sum == 17�Ϳ���move,���������յ�,Ҫ�������ٵ��ƶ�����
//����˼· : ת��һ��,Ȼ�����һ�����·��ģ��

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1e4 + 10;
const int INF = 1e9;

struct Node{
    int v,w;
    Node(int v,int w):v(v),w(w){}
    bool operator < (const Node&rhs) const {
        return rhs.w < w;
    }
};

vector<Node>G[maxn];
bool vis[maxn];
int d[maxn];
int n,m,s,e;

void init(){
    for(int i = 0; i < maxn; i++)G[i].clear();
    for(int i = 0; i < maxn; i++)vis[i] = false;
    for(int i = 0; i < maxn; i++)d[i] = INF;
}

bool Common(char *s1,char *s2){
    int len = strlen(s1);
    int a[10] = {0},b[10] = {0};
    for(int i = 0; i < len; i++)a[s1[i]-'0']++;
    for(int i = 0; i < len; i++)b[s2[i]-'0']++;
    int sum = 0;
    for(int i = 0; i <= 9; i++)sum += min(a[i],b[i]);
    return sum == 17;
}

int dijkstra(int s,int e){ //��������յ�
    priority_queue<Node>q;
    q.push(Node(s,0));
    d[s] = 0;
    while(!q.empty()){
        Node now = q.top(); q.pop();
        int v = now.v;
        if(vis[v])continue;
        vis[v] = true;
        for(int i = 0; i < G[v].size(); i++){
            int v2 = G[v][i].v;
            int w = G[v][i].w;
            if(!vis[v2] && d[v2] > w+d[v]){
                d[v2] = w+d[v];
                q.push(Node(v2,d[v2]));
            }
        }
    }
    return d[e];
}

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    char str[250][25];
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d%d",&n,&s,&e);
        for(int i = 0; i < n; i++)scanf("%s",str[i]);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(Common(str[i],str[j])){
                    G[i].push_back(Node(j,1));
                    G[j].push_back(Node(i,1));
                }
            }
        }
        int ans = dijkstra(s-1,e-1);
        if(INF != ans)printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
