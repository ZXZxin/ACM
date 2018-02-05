//��Ŀ����: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3270
//��Ŀ����: һ����v���������ȫͼ����һ������m��ָ���ߵ����·��
//����˼·:��ÿ���߽�����һ��ʱ��·�����
    /*��һ������������Ϊ0������������Թ���ŷ����·������Ϊ0��������߲����ıߣ�ÿ���߽�����һ�Σ���
    ��һ�����У���������Ϊn�����߲����ı���Ϊ(n-2)/2 ��n-2Ϊ��ȥ�����յ������������
    ����ζ�ţ�����Ҫ�߶����(n-2)/2���߲��ܽ���(n-2)/2��ָ���ĵ��߲����ı����ꡣ���ң���(n-2)/2���߲����ı��ǲ������*/

//�ڽӱ�Ľⷨ:
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>
#include <algorithm>

const int maxn = 1000 + 10;
using namespace std;

struct edge{
    int v,next;
}edge[maxn*50];

int head[maxn];
int in[maxn];
bool vis[maxn];
int ans1,ans2;//�ֱ������ͨ�����Ŀ�� ÿ����ͨ���������Ŀ
int n,m;
int cnt;

void add(int u,int v){
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void DFS(int u){
    ans2 += (in[u]&1); //if(in[u]%2 == 1)ans2 += 1;else ans2 += 0;
    for(int i = head[u]; i != -1; i = edge[i].next){
        if(!vis[edge[i].v]){
            vis[edge[i].v] = true;
            DFS(edge[i].v);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,u,v,kase = 0;
    while(scanf("%d%d%d",&n,&m,&T) && (m || n || T)){
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        /*for(int i = 1; i <= m; i++){
            scanf("%d%d",&u,&v);
            edge[i].v = v;
            edge[i].next = head[u];
            head[u] = i;
            edge[m+i].v = u;
            edge[m+i].next = head[v];
            head[v] = m+i;
            vis[u] = vis[v] = true;
        }*/
         cnt = 0;
         for(int i = 1; i <= m; i++){
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
            in[u]++,in[v]++;
        }
        int sum = 0;
        ans1 = 0;//��ͨ�������
        for(int i = 1; i <= n; i++){
            if(head[i] != -1 && !vis[i]){
                ans1++;  //ͳ����ͨ�������
                ans2 = 0;
                vis[i] = true;
                DFS(i);
                if(ans2 >= 2)sum += (ans2 - 2)/2;
            }
        }
        sum += m;
        if(ans1 >= 2)sum += (ans1 - 1);//��ͨ��ͨ��֮�����:��ͨ�����Ŀ��1
        printf("Case %d: %d\n",++kase,max(0,sum*T));
    }
    return 0;
}

//�ڽӾ���Ľⷨ:(ʱ�䳤һЩ)(����������Ǹ����������)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

const int maxn = 1000 + 10;
using namespace std;
int G[maxn][maxn];
int in[maxn];
int ans1,ans2;//�ֱ������ͨ�����Ŀ�� ÿ����ͨ��ı���
int n,m;

void DFS(int u){
    for(int v = 1; v <= n; v++){
        if(G[u][v]){
            in[u]++;in[v]++;
            G[u][v] = G[v][u] = 0; //����Ϊ�Ѿ�����
            ans2++;//ÿһ����ͨ�������ŷ����·���������Ҫ�ı���(��ʵ���ǵ�����1)
            DFS(v);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,u,v,kase = 0;
    while(scanf("%d%d%d",&n,&m,&T) && (m || n || T)){
        memset(G,0,sizeof(G));
        for(int i = 0; i < m; i++){
            scanf("%d%d",&u,&v);
            G[u][v] = G[v][u] = 1;
        }
        int sum = 0;
        ans1 = 0;//��ͨ�������
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(G[i][j]){
                    ans1++;  //ͳ����ͨ�������
                    memset(in,0,sizeof(in));//Ϊ��ͳ��ÿһ����ͨ��Ķ���
                    ans2 = 0;
                    DFS(i);
                    int ans3 = 0;
                    for(int k = 1; k <= n; k++)if(in[k]%2 == 1)ans3++;//ͳ��������Ŀ
                    if(ans3 >= 2)sum += (ans2 + (ans3 - 2)/2);
                    else sum += (ans2 + (ans3/2));
                }
            }
        }
        if(ans1 >= 2)sum += (ans1 - 1);//��ͨ��ͨ��֮�����:��ͨ�����Ŀ��1
        printf("Case %d: %d\n",++kase,sum*T);
    }
    return 0;
}


//�ڽӾ������һ�ַ���:(��)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

const int maxn = 1000 + 10;
using namespace std;
int G[maxn][maxn];
int in[maxn];
int n,m;

void DFS(int u){
    for(int v = 1; v <= n; v++){
        if(G[u][v]){
            in[u]++;in[v]++;
            G[u][v] = G[v][u] = 0; //����Ϊ�Ѿ�����
            DFS(v);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,u,v,kase = 0;
    while(scanf("%d%d%d",&n,&m,&T) && (m || n || T)){
        memset(G,0,sizeof(G));
        for(int i = 0; i < m; i++){
            scanf("%d%d",&u,&v);
            G[u][v] = G[v][u] = 1;
        }
        int sum = 0;
        int ans1 = 0;//��ͨ�������
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(G[i][j]){
                    ans1++;  //ͳ����ͨ�������
                    memset(in,0,sizeof(in));
                    DFS(i);
                    int ans3 = 0;
                    for(int k = 1; k <= n; k++)if(in[k]%2 == 1)ans3++;//ͳ��������Ŀ
                    if(ans3 >= 2)sum += (ans3 - 2)/2;
                }
            }
        }
        sum += m;
        if(ans1 >= 2)sum += (ans1 - 1);//��ͨ��ͨ��֮�����:��ͨ�����Ŀ��1
        printf("Case %d: %d\n",++kase,sum*T);
    }
    return 0;
}

