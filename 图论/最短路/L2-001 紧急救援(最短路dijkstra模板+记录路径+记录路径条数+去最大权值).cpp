//��Ŀ���� : https://www.patest.cn/contests/gplt/L2-001
//��Ŀ���� : ������
//����˼· : ��Ҫ��TotalRoad��TotalWeight���������ʹ��,��¼��ʱ���������·������,�Լ���ʱ��������������Ա������
/*�����ر�
    1.���·������
    2.����ʱѡ������Ա(���·�����ĵ����ЩȨֵ)�����һ��
    3.��¼·��
*/

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
typedef long long LL;

struct Node{
    int v,w;
    Node(int v,int w):v(v),w(w){}
    bool operator < (const Node&rhs) const {
        return rhs.w < w;
    }
};

vector<Node>G[maxn];
bool vis[maxn];
int Pa[maxn],Weight[maxn],TotalWeight[maxn],TotalRoad[maxn];
int d[maxn];
int n,m,s,e;

void init(){
    for(int i = 0; i < maxn; i++)G[i].clear();
    for(int i = 0; i < maxn; i++)vis[i] = false;
    for(int i = 0; i < maxn; i++)d[i] = INF;
    for(int i = 0; i < maxn; i++)Pa[i] = -1; //��¼·��
    for(int i = 0; i < maxn; i++)TotalRoad[i] = 0;
    for(int i = 0; i < maxn; i++)TotalWeight[i] = 0;
}

void PrintPath(int x){
    if(Pa[x] == -1) printf("%d",x);
    else {
        PrintPath(Pa[x]);
        printf(" %d",x);
    }
}

int dijkstra(int s,int e){ //��������յ�
    priority_queue<Node>q;
    q.push(Node(s,0));
    d[s] = 0, Pa[s] = -1, TotalWeight[s] = Weight[s],TotalRoad[s] = 1;
    while(!q.empty()){
        Node now = q.top(); q.pop();
        int v = now.v;
        if(vis[v])continue;
        vis[v] = true;
        for(int i = 0; i < G[v].size(); i++){
            int v2 = G[v][i].v;
            int w = G[v][i].w;
            if(!vis[v2] && d[v2] > w+d[v]){
                d[v2] = w + d[v];
                TotalWeight[v2] = TotalWeight[v] + Weight[v2];
                Pa[v2] = v;
                TotalRoad[v2] = TotalRoad[v];
                q.push(Node(v2,d[v2]));
            }
            else if(!vis[v2] && d[v2] == w+d[v]){
                if(TotalWeight[v2] < TotalWeight[v] + Weight[v2]){ //�������Ա��������
                    TotalWeight[v2] = TotalWeight[v] + Weight[v2];
                    Pa[v2] = v;
                    //q.push(Node(v2,d[v2]));����Ҫ�����
                }
                TotalRoad[v2] += TotalRoad[v]; //����֮ǰ������
            }
        }
    }
    return d[e];
}

int main(){
    //freopen("in.txt","r",stdin);
    int a,b,c;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i = 0; i < n; i++)scanf("%d",&Weight[i]);
    init();
    for(int i = 0; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(Node(b,c));
        G[b].push_back(Node(a,c));
    }
    int ans = dijkstra(s,e);
    //if(INF != ans)printf("%d\n",ans); else printf("-1\n");
    printf("%d %d\n",TotalRoad[e],TotalWeight[e]);
    PrintPath(e);
    printf("\n");
    return 0;
}
