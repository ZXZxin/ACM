//���������� (һ)  ʹ��ȫ���еı���/���루���Ч��(�������صļ���)
//·��Ѱ������(״̬�ռ�����)��ʵ���� : ��һ��״̬����һ��״̬  ��·��

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

typedef int State[9];
const int maxn = 9*8*7*6*5*4*3*2*1 + 10;//�����ô����״̬
using namespace std;

struct node{
    int num[9];
    int step;
};

int st[maxn][9],goal[9];
int dist[maxn];
int vis[maxn],fact[9];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sum = 0;//���д���

void init_lookup_table() {
    fact[0] = 1;
    for(int i = 1; i < 9; i++) fact[i] = fact[i-1] * i;
}

int try_to_insert(int s) {
    int code = 0;
    for(int i = 0; i < 9; i++) {
        int cnt = 0;
        for(int j = i+1; j < 9; j++) if(st[s][j] < st[s][i]) cnt++;
        code += fact[8-i] * cnt;
    }
    if(vis[code]) return 0;
    return vis[code] = 1;
}

int BFS(){
    init_lookup_table();
    int front = 1,rear = 2;
    //int s[9],t[9];
    while(front < rear){
        sum++;  //��¼ѭ������
        //memcpy(s,st[front],sizeof(st[front]));
        State& s = st[front];
        if(memcmp(goal,s,sizeof(s)) == 0)return front;
        int z;
        for(z = 0; z < 9; z++)if(s[z] == 0)break;
        int x = z/3,y = z%3;
        for(int i = 0; i < 4; i++){
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int newz = newx*3 + newy;
            if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                State& t = st[rear];//���õĻ���ʡ����
                memcpy(t,s,sizeof(t));
                t[newz] = s[z];
                t[z] = s[newz];
                //memcpy(st[rear],t,sizeof(t));//û�����õĻ���Ҫ����
                dist[rear] = dist[front] + 1;
                if(try_to_insert(rear))rear++;
            }
        }
        front++;//����
    }
    return -1;
}

int main(){
    freopen("in.txt","r",stdin);
    memset(dist,0,sizeof(dist));
    for(int i = 0; i < 9; i++)scanf("%d",&st[1][i]);
    for(int i = 0; i < 9; i++)scanf("%d",&goal[i]);
    int ans = BFS();
    if(ans == -1)printf("-1\n");
    else printf("%d\n",dist[ans]);
    printf("����ѭ������ : %d\n",sum);
    return 0;
}

/*
��������:
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
���:
31
����ѭ������: 181440
*/


//STL   queue���а�

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

const int maxn = 9*8*7*6*5*4*3*2*1 + 10;//�����ô����״̬
using namespace std;

struct node{
    int num[9];
    int step;
};

int st[maxn][9],goal[9];
int vis[maxn],fact[9];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sum = 0;//���д���

void init_lookup_table(){
    fact[0] = 1;
    for(int i = 1; i < 9; i++)fact[i] = fact[i - 1]*i;
}

bool try_to_insert(int s){
    int code = 0;
    for(int i = 0; i < 9; i++){
        int cnt = 0;
        for(int j = i + 1; j < 9; j++)if(st[s][j] < st[s][i])cnt++;
        code += fact[8-i]*cnt;
    }
    if(vis[code])return false;
    vis[code] = true;
    return true;
}


int BFS(int step){
    init_lookup_table();
    node Now,Next;
    Now.step = step;
    memcpy(Now.num,st[1],sizeof(st[1]));
    vis[step] = true;
    queue<node>q;
    q.push(Now);
    while(!q.empty()){
        sum++;
        Now = q.front();q.pop();
        if(memcmp(goal,Now.num,sizeof(Now.num)) == 0)return Now.step;
        int z;
        for(z = 0; z < 9; z++)if(Now.num[z] == 0)break;
        int x = z/3,y = z%3;
        for(int i = 0; i < 4; i++){
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            int newz = newx*3 + newy;
            if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3){
                memcpy(Next.num,Now.num,sizeof(Now.num));
                Next.num[newz] = Now.num[z];
                Next.num[z] = Now.num[newz];
                Next.step = Now.step + 1;
                memcpy(st[Next.step],Next.num,sizeof(Next.num));//�ǵð������st��ά����,�����ж�״̬��ʱ��Ҫʹ��
                if(try_to_insert(Next.step)){q.push(Next);}
            }
        }
    }
    return -1;
}

int main(){
    freopen("in.txt","r",stdin);
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < 9; i++)scanf("%d",&st[1][i]);
    for(int i = 0; i < 9; i++)scanf("%d",&goal[i]);
    printf("%d\n",BFS(0));
    printf("����ѭ������ : %d\n",sum);
    return 0;
}


