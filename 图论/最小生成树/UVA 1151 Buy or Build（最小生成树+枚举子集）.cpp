//��Ŀ���ӣ�https://vjudge.net/contest/192155#problem/C
/*��Ŀ���⣺��ƽ������n���㣬Ҫ������n���㶼��ͨ��������Ҫ����һЩ������ͨ����
            ��ͨ�ķ��õ��������˵��ŷ����þ����ƽ�������⻹��q���ײ�
            ���Թ�������㹺���˵�i���ײͣ����ײ��е����н�㽫����໥��ͨ
            ��i���ײ͵Ļ���Ϊci������С����*/
//����˼·:������ö��ʱ�临�Ӷ����Գ��ܡ����ȶ�ԭͼ����С�������õ�n-1���ߣ�
            //ÿ��ö���ײ�ʱ�������ײ��еıߺ���n-1�ߣ����ײ��еı�Ȩֵ��Ϊ0����n-1��������С���������ɣ�

#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
const int  maxn =  1000+50;
#define INF 1000000000

using namespace std;

struct Point{
    int x,y;
}m[maxn];

struct Edge{
    int u,v,w;
    Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};

int cmp(Edge a,Edge b){
    return a.w<b.w;
}

Edge arc[maxn*maxn+50];
vector<int>a[10];
vector<Edge>edge;
vector<Edge>tempE;
int n,q,sum;
int pa[maxn];

void init(){
    for(int i=0;i<=n;i++)pa[i]=i;
}

int find(int u){
    if(u==pa[u])return u;
    else return pa[u]=find(pa[u]);
}

double cacluate(int i,int j){
    return (m[i].x-m[j].x)*(m[i].x-m[j].x)+(m[i].y-m[j].y)*(m[i].y-m[j].y);
}

void kuaskal(){
    for(int s=0;s<(1<<q);s++){//������ö���Ӽ�
        init();
        tempE=edge;
        int tot=0,tmp=0;
        for(int i=0;i<q;i++){
            if(s&(1<<i)){
                tmp+=a[i][0];
                for(int j=1;j<a[i].size();j++)
                    for(int k=j+1;k<a[i].size();k++)
                    tempE.push_back(Edge(a[i][j]-1,a[i][k]-1,0));
            }
        }
        sort(tempE.begin(),tempE.end(),cmp);
        for(int i=0;i<tempE.size();i++){
            int x=find(tempE[i].u);
            int y=find(tempE[i].v);
            if(x!=y){
                pa[x]=y;
                tot++;
                tmp+=tempE[i].w;
                if(tot==n-1){
                    sum=min(sum,tmp);
                    break;
                }
            }
        }
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    int T,kase=0;
    cin>>T;
    while(T--){
        if(++kase!=1)cout<<endl;
        sum=0;
        edge.clear();
        cin>>n>>q;
        for(int i=0;i<q;i++)a[i].clear();
        for(int i=0;i<q;i++){
            int k,cost;
            cin>>k>>cost;
            a[i].push_back(cost);
            for(int j=0;j<k;j++){
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        for(int i=0;i<n;i++){
             cin>>m[i].x>>m[i].y;
        }
        init();
        int num=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                arc[num++]=Edge(i,j,cacluate(i,j));
            }
        }
        sort(arc,arc+num,cmp);
        int total=0;
        sum=0;
        for(int i=0;i<num;i++){
            int x=find(arc[i].u);
            int y=find(arc[i].v);
            if(x!=y){
                pa[x]=y;
                total++;
                sum+=arc[i].w;
                edge.push_back(Edge(arc[i].u,arc[i].v,arc[i].w));
            }
            if(total==n-1)break;
        }
        kuaskal();
        cout<<sum<<endl;
    }
    return 0;
}



