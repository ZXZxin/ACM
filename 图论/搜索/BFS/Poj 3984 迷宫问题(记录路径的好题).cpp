//题目链接;http://poj.org/problem?id=3984
//题目大意：给你一个5*5的矩阵，让你找一条路，从左上点，到右下点
//解题思路:利用BFS求解最短路，利用vector记录路径

//BFS+在结构体中记录路径
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <string>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;
const int maxn = 100 + 10;

int n;
int map[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};//对应上，右，下，左

struct Road {//路径记录
    int x,y,d;//d表示方向
    Road() {}//默认的构造函数
    Road(int a,int b,int c):x(a),y(b),d(c) {}//带参数的构造函数
};

struct node {//节点类型
    int x,y;
    vector<Road> v;//记录路径的结构体
};

bool check(node u) {
    if (!vis[u.x][u.y] && u.x >= 0 && u.x < n && u.y >= 0 && u.y < n && map[u.x][u.y] != 1)
        return true;
    else
        return false;
}

void BFS(int x, int y) {
    queue<node>q;
    node now,next;
    now.x = x;
    now.y = y;
    now.v.push_back(Road(x,y,-1));
    q.push(now);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        if (now.x == n - 1 && now.y == n-1) {
            for(int i = 0; i < now.v.size(); i++){
                printf("(%d, %d)\n",now.v[i].x,now.v[i].y);
            }
            break;
        }
        for (int i = 0; i < 4; i++) {
            next.x = now.x + dir[i][0];
            next.y = now.y + dir[i][1];
            if (check(next)) {
                vis[next.x][next.y] = true;
                next.v = now.v;
                next.v[now.v.size()-1].d = i;
                next.v.push_back(Road(next.x,next.y,-1));
                q.push(next);
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    flag = false;
    n = 5;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    BFS(0, 0);
    return 0;
}

//BFS+记录路径
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;

int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool vis[maxn][maxn];
int map[maxn][maxn];

struct Node {
    int x,y,pre;
};

Node m_queue[maxn];

bool Check(int x,int y){
    if(!map[x][y] && !vis[x][y] && x >= 0 && x < 5&&y >= 0 && y < 5)return true;
    else return false;
}

void print(int u){
    if(m_queue[u].pre != -1){
        print(m_queue[u].pre);
        printf("(%d, %d)\n",m_queue[u].x,m_queue[u].y);
    }
}

void BFS(int x,int y){
    int head = 0,rear = 1;
    m_queue[head].x = x;
    m_queue[head].y = y;
    m_queue[head].pre = -1;
    vis[x][y] = true;
    while(head < rear){
        for(int i = 0; i < 4; i++){
            int xx = m_queue[head].x + dir[i][0];
            int yy = m_queue[head].y + dir[i][1];
            if(Check(xx,yy)){
                vis[xx][yy] = 1;
                m_queue[rear].x = xx;
                m_queue[rear].y = yy;
                m_queue[rear].pre = head;
                rear++;
            }
            if(xx == 4&&yy == 4)print(rear - 1);
        }
        head++;//出队
    }
}


int  main(){
    //freopen("in.txt","r",stdin);
    int n = 5;
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&map[i][j]);
        }
    }
    printf("(0, 0)\n");
    BFS(0,0);
    return 0;
}
//DFS加回溯法
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;
const int maxn = 100+10;
const int INF = 0x3f3f3f3f;

int n,k,ans = INF;
int map[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

struct node {
    int x,y;
};
vector<node>dict;
stack<node>s;

void memcpy(stack<node>s){
    dict.clear();
    while(!s.empty()){
        dict.push_back(s.top());
        s.pop();
    }
}

bool Check(int x,int y){
    if(!vis[x][y] && map[x][y] != 1 && x >= 0 && x < n && y >= 0 && y < n)return true;
    else return false;
}

void DFS(int x,int y,int step){//深刻理解递归的含义
    node now;
    now.x = x;
    now.y = y;
    s.push(now);
    if(now.x == n - 1 &&now.y == n - 1){
        if(step < ans){//记录最短的路径
            ans = step;
            memcpy(s);
        }
    }
    for(int i = 0; i < 4; i++){
        int xx = now.x + dir[i][0];
        int yy = now.y + dir[i][1];
        if(Check(xx,yy)){
            vis[xx][yy] = true;
            DFS(xx,yy,step + 1);
            vis[xx][yy] = false;//回溯
        }
    }
    s.pop();//反弹的时候重新还原栈
}

int main(){
    //freopen("in.txt","r",stdin);
    n = 5;
    memset(vis,false,sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&map[i][j]);
        }
    }
    DFS(0,0,0);
    for(int i = dict.size() - 1; i >= 0; i--){
        printf("(%d, %d)\n",dict[i].x,dict[i].y);
    }
    return 0;
}





