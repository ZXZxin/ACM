//八数码问题(二) : 使用哈希表（竞赛中最常用）(判重)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

typedef int State[9];
const int maxn = 9*8*7*6*5*4*3*2*1 + 10;//最多这么多种状态
const int HashSize = 1000003; //哈希表除数取余法的最大取余数
using namespace std;

struct node{
    int num[9];
    int step;
};

int st[maxn][9],goal[9];
int dist[maxn];
int head[HashSize],nxt[HashSize];//哈希表的头结点,next指针(相当于单链表)
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sum = 0;//运行次数

int Hash(State& s){  // 哈希函数
    int v = 0;
    for(int i = 0; i < 9; i++)v = v*10 + s[i];
    return v % HashSize;
}

bool try_to_insert(int s){    //哈希链表的查找
    int h = Hash(st[s]);
    int u = head[h];
    while(u){
        if(memcmp(st[u],st[s],sizeof(st[s])) == 0)return false;
        u = nxt[u];
    }
    nxt[s] = head[h];//头插法插入哈希链表
    head[h] = s;
    return true;
}

int BFS(){
    memset(head,0,sizeof(head));//哈希链表的头结点
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

//STL:  queue版 (不知道为什么sum的值多出了5倍)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

const int HashSize = 1000003;
const int maxn = 9*8*7*6*5*4*3*2*1 + 10;//最多这么多种状态
using namespace std;

struct node{
    int num[9];
    int step;
};

int st[maxn][9],goal[9];
int head[HashSize],nxt[HashSize];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int sum = 0;//运行次数

int Hash(int s[9]){  // 哈希函数
    int v = 0;
    for(int i = 0; i < 9; i++)v = v*10 + s[i];
    return v % HashSize;
}

bool try_to_insert(int s){
    int h = Hash(st[s]);
    int u = head[h];
    while(u){
        if(memcmp(st[u],st[s],sizeof(st[s])) == 0)return false;
        u = nxt[u];
    }
    nxt[s] = head[h];//头插法插入哈希链表
    head[h] = s;
    return true;
}

int BFS(int step){
    memset(head,0,sizeof(head));
    node Now,Next;
    Now.step = step;
    memcpy(Now.num,st[1],sizeof(st[1]));
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
                if(try_to_insert(Next.step))q.push(Next);
            }
        }
    }
    return -1;
}

int main(){
    freopen("in.txt","r",stdin);
    for(int i = 0; i < 9; i++)scanf("%d",&st[1][i]);
    for(int i = 0; i < 9; i++)scanf("%d",&goal[i]);
    printf("%d\n",BFS(0));
    printf("队列循环次数 : %d\n",sum);
    return 0;
}

