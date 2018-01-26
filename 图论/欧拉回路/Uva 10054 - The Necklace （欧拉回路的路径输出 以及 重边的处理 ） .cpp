//��Ŀ����:https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=995
//��Ŀ����:����n�����ӣ�һ�����ӷ�Ϊ������������ɫ����1��50����ʾ50�ֲ�ͬ����ɫ������Щ���Ӵ�����
          //���������ŵ�����Ҫ����һ���������ǽӴ����ǲ�����ɫҪ��ͬ
//����˼·��Ҳ��һ������ŷ����·��Ӧ���Լ�·������������о��������Ŀ���������ر�
         //Ҳ����g[i][j]��ֵ��һ��ֻ��Ϊ1��Ȼ���һ����������ҵ����������ĵ㣬Ȼ��ɾ����������ߣ�������g[u][v]--;g[v][u]--
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
struct node{
    int u,v;
    node(){}
    node(int u,int v):u(u),v(v){}
};
const int maxn = 1000 + 10;
using namespace std;
int G[maxn][maxn],in[maxn];
bool vis[maxn];
stack<node>s;

void dfs(int u){  //�ж��Ƿ���ͨ
    vis[u] = 1;
    for(int i = 1; i <= 50; i++){
        if(!vis[i] && G[u][i]) {
            dfs(i);
        }
    }
}

void euler(int u){  // ���·��
    for(int i = 1; i <= 50; i++){
        if(G[u][i]) {
            G[u][i]--;G[i][u]--;
            euler(i);
            s.push(node(u,i));
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,u,v;
    scanf("%d",&T);
    int kase = 0;
    while(T--){
        memset(vis,1,sizeof(vis));
        memset(G,0,sizeof(G));
        memset(in,0,sizeof(in));
        while(!s.empty())s.pop();
        bool flag = true;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d %d",&u,&v);
            G[u][v]++; G[v][u]++;
            in[v]++;in[u]++;
            vis[u] = vis[v] = 0;
        }
        for(int i = 1; i <= 50; i++)if(in[i]%2 != 0){
            flag = false;
            break;
        }
        dfs(u);
        for(int i = 1; i <= 50; i++)if(!vis[i]){
            flag = false;
            break;
        }
        printf("Case #%d\n",++kase);
        if(!flag){
            printf("some beads may be lost\n");
            if(T != 0)printf("\n");
            continue;
        }
        euler(u);
        while(!s.empty()){
            printf("%d %d\n",(s.top()).u,(s.top()).v);
            s.pop();
        }
        if(T != 0)printf("\n");
    }
    return 0;
}
