//��Ŀ���ӣ�https://vjudge.net/contest/169967#problem/E
//�����ţ�������Ҫ��һ��n*m����������Ͻǣ�1,1���ߵ����½ǣ�m��n��,0��ʾ�յأ�1��ʾ�ϰ���
         //������ÿ�ο������ĸ�������һ�񣬵����������ش�Խk���ϰ��������·���ȡ������յ㱣֤�ǿյء�
//����˼·����bfs�������ɣ����ڲ��������ش�Խk���ϰ���������ԭ����vis2ά�������������1ά�����3ά���飬��ʾ��Խ��ǽ�Ĳ������ϰ�����
           //������⣬��ʵ�����е�û��
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

const int maxn = 20 + 10;
using namespace std;

int n,m,k;
int Map[maxn][maxn];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool vis[maxn][maxn][maxn];

struct node{
    int x,y,step,layer;
    node(int x = 0,int y = 0,int step = 0,int layer = 0):x(x),y(y),step(step),layer(layer){}
};

bool check(int x,int y,int layer){
    if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y][layer] && layer <= k)return true;
    else return false;
}

int BFS(int x,int y){
    memset(vis,false,sizeof(vis));
    node Now,Next;
    Now.x = x,Now.y = y,Now.step = 0,Now.layer = 0;
    vis[Now.x][Now.y][0] = true;
    queue<node>q;
    q.push(Now);
    while(!q.empty()){
        Now = q.front();q.pop();
        if(Now.x == n - 1 && Now.y == m - 1)return Now.step;
        for(int i = 0; i < 4; i++){
            Next.x = Now.x + dir[i][0];
            Next.y = Now.y + dir[i][1];
            if(Map[Next.x][Next.y])Next.layer = Now.layer + 1;
            else Next.layer = 0;
            if(check(Next.x,Next.y,Next.layer)){
                vis[Next.x][Next.y][Next.layer] = true;
                Next.step = Now.step + 1;
                q.push(Next);
            }
        }
    }
    return -1;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d",&Map[i][j]);
            }
        }
        printf("%d\n",BFS(0,0));
    }
    return 0;
}
