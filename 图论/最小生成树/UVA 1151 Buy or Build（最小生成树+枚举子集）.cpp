//题目链接：https://vjudge.net/contest/192155#problem/C
/*题目大意：在平面上有n个点，要让所有n个点都连通，所以你要构造一些边来连通他们
            连通的费用等于两个端点的欧几里得距离的平方。另外还有q个套餐
            可以购买，如果你购买了第i个套餐，该套餐中的所有结点将变得相互连通
            第i个套餐的花费为ci。求最小花费*/
//解题思路:：单纯枚举时间复杂度难以承受。则先对原图求最小生成树得到n-1条边，
            //每次枚举套餐时仅考虑套餐中的边和这n-1边（将套餐中的边权值置为0和这n-1条边求最小生成树即可）

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
    for(int s=0;s<(1<<q);s++){//二进制枚举子集
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



