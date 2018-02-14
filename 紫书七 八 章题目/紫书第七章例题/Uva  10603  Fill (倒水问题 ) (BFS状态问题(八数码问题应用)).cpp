//��Ŀ����:https://vjudge.net/contest/171111#problem/H
//��Ŀ����:���Ǹ���a,b,c����ƿ�ӵ�����,ֻ��c��װ����ˮ,a,b,cû�п̶�,Ҫ������d��ˮ,���������,����ӽ�d��ˮʱ�ĵ�����С��ˮ���Լ�d
//����˼·: �����BFS�����·��״̬����(����������),����ע�⵽vis��������ά��,�������ǰ����a,bȷ��(��ͬ)�Ļ�,�Ϳ����ж�
           //��������Ŀǰ����ˮ������,����ѡ�����ȶ���
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

const int maxn = 200 + 10;
using namespace std;

bool vis[maxn][maxn];
int cap[3],ans[maxn];

struct Node{
    int v[3];
    int dist;//��Ŀǰ״̬������ˮ��
    bool operator < (const Node& rhs)const{ //����<�����
        return dist > rhs.dist;
    }
};

void update_ans(const Node& u){
    for(int i = 0; i < 3; i++){
        int d = u.v[i];  //����Ҫ��ÿһ��״̬�� ����ƿ�ӵ� ans�����,������ֻ��һ��,��Ϊ����Ҫ��d
        if(ans[d] == -1 || u.dist < ans[d])ans[d] = u.dist;
    }
}

void BFS(int a,int b,int c,int d){
    cap[0] = a,cap[1] = b,cap[2] = c;
    memset(vis,false,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<Node>q;

    Node Now,Next;
    Now.dist = 0,Now.v[0] = 0,Now.v[1] = 0,Now.v[2] = c;
    vis[Now.v[0]][Now.v[1]] = true;
    q.push(Now);
    while(!q.empty()){
        Now = q.top();q.pop();
        update_ans(Now);
        if(ans[d] != -1)break;  //�Ѿ����¹�(�Ѿ��ﵽ)�Ͳ�����
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if( i != j ){
                    if(Now.v[j] == cap[j] || Now.v[i] == 0)continue;
                    int amount = min(cap[j],Now.v[i] + Now.v[j]) - Now.v[j];  //����ǵ���v[j],���ǵ���v[j];

                    memcpy(Next.v,Now.v,sizeof(Now.v));
                    Next.dist = Now.dist + amount;
                    Next.v[i] -= amount;
                    Next.v[j] += amount;

                    if(!vis[Next.v[0]][Next.v[1]]){  //visֻ�ж�ά��ԭ����  ���ǰ�������ӵ�ˮ��ͬ,����������ӵ�ˮҲ��ͬ,����ֻҪ��ǰ��������
                        vis[Next.v[0]][Next.v[1]] = true;
                        q.push(Next);
                    }
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        BFS(a,b,c,d);
        for(int i = d; i >= 0; i--){//ǰ���Ǳ�֤�ӽ�d
            if(ans[i] != -1){printf("%d %d\n",ans[i],i);break;}  //ע�ⲻҪ��breakд������

        }
    }
    return 0;
}



//��������ѵĸĽ�:
//����dist[][]��ά�����ٴ�����  �Լ�  dijkstra�㷨

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

const int maxn = 200 + 10;
using namespace std;

bool vis[maxn][maxn];
int dist[maxn][maxn],cap[3],ans[maxn];//dist������ʵ���Ǽ�¼ÿһ��״̬�е�u.dist

struct Node{
    int v[3];
    int dist;//��Ŀǰ״̬������ˮ��
    bool operator < (const Node& rhs)const{ //����<�����
        return dist > rhs.dist;
    }
};

void update_ans(const Node& u){
    for(int i = 0; i < 3; i++){
        int d = u.v[i];  //����Ҫ��ÿһ��״̬�� ����ƿ�ӵ� ans�����,������ֻ��һ��,��Ϊ����Ҫ��d
        if(ans[d] < 0 || u.dist < ans[d])ans[d] = u.dist;
    }
}

void BFS(int a,int b,int c,int d){
    cap[0] = a,cap[1] = b,cap[2] = c;
    memset(vis,false,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    memset(dist,-1,sizeof(dist));
    priority_queue<Node>q;

    Node Now,Next;
    Now.dist = 0,Now.v[0] = 0,Now.v[1] = 0,Now.v[2] = c;
    dist[Now.v[0]][Now.v[1]] = 0;
    q.push(Now);
    while(!q.empty()){
        Now = q.top();q.pop();
        if(vis[Now.v[0]][Now.v[1]])continue;
        vis[Now.v[0]][Now.v[1]] = true;
        update_ans(Now);
        if(ans[d] >= 0)break;  //�Ѿ����¹�(�Ѿ��ﵽ)�Ͳ�����
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if( i != j ){
                    if(Now.v[j] == cap[j] || Now.v[i] == 0)continue;
                    int amount = min(cap[j],Now.v[i] + Now.v[j]) - Now.v[j];  //����ǵ���v[j],���ǵ���v[j];

                    memcpy(&Next,&Now,sizeof(Now));
                    Next.dist = Now.dist + amount;
                    Next.v[i] -= amount;
                    Next.v[j] += amount;

                    if(dist[Next.v[0]][Next.v[1]] < 0  || dist[Next.v[0]][Next.v[1]] > Next.dist){  //visֻ�ж�ά��ԭ����  ���ǰ�������ӵ�ˮ��ͬ,����������ӵ�ˮҲ��ͬ,����ֻҪ��ǰ��������
                        dist[Next.v[0]][Next.v[1]] = Next.dist;
                        q.push(Next);
                    }
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        BFS(a,b,c,d);
        for(int i = d; i >= 0; i--){  //ǰ���Ǳ�֤�ӽ�d
            if(ans[i] >= 0){
                printf("%d %d\n",ans[i],i);
                break;
            }
        }
    }
    return 0;
}
