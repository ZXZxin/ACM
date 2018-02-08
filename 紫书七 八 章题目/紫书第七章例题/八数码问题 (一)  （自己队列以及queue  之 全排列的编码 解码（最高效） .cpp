//八数码问题 (一)  使用全排列的编码/解码（最高效）(就是判重的技巧)
//路径寻找问题(状态空间搜素)其实就是 : 从一个状态到另一个状态  的路径

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

typedef int State[9];
const int maxn = 9*8*7*6*5*4*3*2*1 + 10;//最多这么多种状态
using namespace std;

struct node{
    int num[9];
    int step;
};

int st[maxn][9],goal[9];
int dist[maxn];
int vis[maxn],fact[9];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sum = 0;//运行次数

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
        sum++;  //记录循环次数
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
                State& t = st[rear];//引用的话更省代码
                memcpy(t,s,sizeof(t));
                t[newz] = s[z];
                t[z] = s[newz];
                //memcpy(st[rear],t,sizeof(t));//没有引用的话就要这样
                dist[rear] = dist[front] + 1;
                if(try_to_insert(rear))rear++;
            }
        }
        front++;//出队
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
    printf("队列循环次数 : %d\n",sum);
    return 0;
}

/*
测试数据:
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
输出:
31
队列循环次数: 181440
*/


//STL   queue队列版

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

const int maxn = 9*8*7*6*5*4*3*2*1 + 10;//最多这么多种状态
using namespace std;

struct node{
    int num[9];
    int step;
};

int st[maxn][9],goal[9];
int vis[maxn],fact[9];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sum = 0;//运行次数

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
                memcpy(st[Next.step],Next.num,sizeof(Next.num));//记得把这个给st二维数组,等下判断状态的时候要使用
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
    printf("队列循环次数 : %d\n",sum);
    return 0;
}


