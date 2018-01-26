//��Ŀ���ӣ�http://acm.hdu.edu.cn/showproblem.php?pid=1878
//��Ŀ���⣺��ֱ�׵�����ŷ����·���ж�
//����˼·��ֱ����DFS�ж��ǲ�����ͨ�ģ�Ȼ���ж�ÿ����Ķ����ǲ���ż����OK

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 1000 + 5;
using namespace std;

int vis[maxn];
int G[maxn][maxn];
int in[maxn];
int n,m;

void DFS(int u){
    vis[u] = 1;
    for(int i = 1; i <= n; i++){
        if(G[u][i] && !vis[i])DFS(i);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int u,v;
    while(scanf("%d",&n) != EOF && n != 0){
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        memset(in,0,sizeof(in));
        bool flag = true;
        for(int i = 0; i < m; i++){
            scanf("%d%d",&u,&v);
            G[u][v] = 1;
            in[u]++;
            in[v]++;
        }
        DFS(1);
        for(int i = 1; i <= n; i++){
            if(in[i] % 2 != 0)flag = false;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i])flag = false;
        }
        if(flag)printf("1\n");
        else printf("0\n");
    }
    return 0;
}
