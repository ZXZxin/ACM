//��Ŀ���ӣ�https://vjudge.net/contest/192155#problem/B
//��Ŀ���⣺����һ��ͼ��Ҫ�������߼���С����С��������
//����˼·��ö��ÿһ���ߣ�����[L,R]����������䣬�����Щ����պ�����һ������������һ������һ�������Ȳ�����W[R]-W[L]��������

//����ʵ��
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#define maxn 10010
#define INF 1000000000

using namespace std;
int pa[maxn];

int v[maxn],u[maxn],w[maxn];
int r[maxn];

bool cmp(int x,int y){
    return w[x]<w[y];
}

int find(int u){
    if(u==pa[u])return u;
    else return pa[u]=find(pa[u]);
}

int main() {
    freopen("in.txt","r",stdin);
    int n,m;
    while(cin>>n>>m&&(m||n)){
        for(int i=0;i<m;i++){
            cin>>u[i]>>v[i]>>w[i];
        }
        for(int i=0;i<m;i++)r[i]=i;
        sort(r,r+m,cmp);
        int ans=INF;
        for(int i=0;i<m;i++){//ö��ÿһ����Сֵ����ÿһ������Ϊ��ʼ�ߵ�������
            for(int x=0;x<=n;x++)pa[x]=x;
            int cnt=0;
            for(int j=i;j<m;j++){//��¼�����������ߣ��������һ����������ʱ�������һ����������ֵ
                int e=r[j];
                int u1=find(u[e]);
                int v1=find(v[e]);
                if(v1!=u1){
                    pa[u1]=v1;
                    cnt++;
                    if(cnt==n-1){
                        ans=min(ans,w[r[j]]-w[r[i]]);
                    }
                }
            }
        }
        if(ans==INF)cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}


//�ṹ���STL
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#define maxn 100+10
#define INF 1000000000

using namespace std;
int pa[maxn];

struct Edge{
    int u,v,w;
    Edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const Edge&rhs)const{
        return w<rhs.w;
    }
};

vector<Edge>G;

int find(int u){
    if(u==pa[u])return u;
    else return pa[u]=find(pa[u]);
}

int main() {
    //freopen("in.txt","r",stdin);
    int n,m;
    while(cin>>n>>m&&(m||n)){
        G.clear();
        for(int i=0;i<m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            G.push_back(Edge(u,v,w));
        }
        sort(G.begin(),G.end());
        int ans=INF;
        for(int L=0;L<m;L++){
            for(int i=1;i<=n;i++)pa[i]=i;
            int cnt=n;
            for(int R=L;R<m;R++){
                int u=find(G[R].u);int v=find(G[R].v);
                if(v!=u){
                    pa[u]=v;
                    if(--cnt==1){
                        ans=min(ans,G[R].w-G[L].w);
                    }
                }
            }
        }
        if(ans==INF)cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}







