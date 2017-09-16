#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#define maxn 1000
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
int dist[maxn];
int flag[maxn];

struct HeapNode
{
    int d,u;
    HeapNode (int d,int u):d(d),u(u) {}
    bool operator < (const HeapNode &rhs)const
    {
        return d>rhs.d;
    }
};

struct Edge
{
    int from,to,weight;
};

vector<Edge>edge;
vector<int>G[maxn];

void init()
{
    for(int i=1; i<=n; i++)
        G[i].clear();
    edge.clear();
}

void addedge(int from,int to,int cost)
{
    edge.push_back((Edge)
    {
        from,to,cost
    });
    int len=edge.size();
    G[from].push_back(len-1);
}

void DIJ(int s)
{
    priority_queue<HeapNode>q;
    memset(flag,false,sizeof(flag));
    for(int i=1; i<=n; i++)
        dist[i]=INF;
    dist[s]=0;
    q.push((HeapNode)
    {
        0,s
    });
    while(!q.empty())
    {
        HeapNode x=q.top();
        q.pop();
        int u=x.u;
        if(flag[u])continue;
        flag[u]=true;
        for(int i=0; i<G[u].size(); i++)
        {
            Edge& e=edge[G[u][i]];
            if(dist[e.to]>dist[u]+e.weight)
            {
                dist[e.to]=dist[u]+e.weight;
                q.push(HeapNode(dist[e.to],e.to));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin>>m>>n;
    for(int i=1; i<=m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        addedge(x,y,z);
        addedge(y,x,z);
    }
    DIJ(1);
    cout<<dist[n];
    return 0;
}
