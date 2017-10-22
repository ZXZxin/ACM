//题目链接：https://vjudge.net/contest/192155#problem/E
//题目大意：输入n个点m条边的无向带权图，边权表示该路径上的噪声值，
           //输入一些询问，每次询问两个点输出这两个点间最大噪声值最小的路径
//解题思路：floyd的变形  d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));



#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

const int maxn = 100+5;
const int INF = 10000000;
using namespace std;

int d[maxn][maxn];
int n,m,T;

void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]<INF&&d[k][j]<INF)
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
            }
        }
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int kase=0;
    while(cin>>n>>m>>T&&n){
        for(int i=0;i<n;i++){
            d[i][i]=0;
            for(int j=i+1;j<n;j++){
                d[i][j]=d[j][i]=INF;
            }
        }
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            x--;y--;
            d[x][y]=min(z,d[x][y]);
            d[y][x]=d[x][y];
        }
        floyd();
        if(kase)cout<<endl;
        cout<<"Case #"<<++kase<<endl;
        for(int i=0;i<T;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        if(d[u][v]!=INF)
             cout<<d[u][v]<<endl;
        else cout<<"no path"<<endl;
        }
    }
    return 0;
}


