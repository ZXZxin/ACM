//题目链接：https://vjudge.net/contest/169966#problem/N
//题目大意：就是要你找一条从起点到终点的最短路，注意有方向dir，以及记录路径
//解题思路：主要是要掌握方向的设置以及字符与数字的转换，以及Walk函数的使用，以及其中顺时针以及逆时针的使用

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;
const int maxn = 10;
const int dr[] = {-1,0,1,0};//方向  对应  上右下左//顺时针//北东南西 0123
const int dc[] = {0,1,0,-1};
const char *dirs = "NESW";//顺时针方向//上右下左
const char *turns = "FLR";//直行,左转,右转

struct Node{
    int r,c,dir;
    Node(int r = 0,int c = 0,int dir = 0):r(r),c(c),dir(dir){}
};
int d[maxn][maxn][4];//最短路径
Node p[maxn][maxn][4];//记录上一步的状态
int r0,c0,r1,c1,r2,c2,dir;
int has_edge[maxn][maxn][4][3];//当前状态的可走的状态
bool flag;

int dir_id(char c){return strchr(dirs,c) - dirs;}//返回出现某个字符的位置
int turn_id(char c){return strchr(turns,c) - turns;}

bool Check(Node u,int i){
    if(d[u.r][u.c][u.dir] < 0 && u.r <= 9 && u.r >= 1 && u.c <= 9 && u.c >=1)return true;
    else return false;
}

Node Walk(const Node& u,int turn){//行走探索的函数
    int dir = u.dir;
    if(turn == 1)dir = (dir + 3)%4; //向左转//例如朝东（E(1)） --> (1_+ 3)%4 = 0 -->变成朝北 -->实现左转
    else if(turn == 2)dir = (dir + 1)%4;//向右转
    return Node(u.r + dr[dir],u.c + dc[dir],dir);
}

void Print(Node u){
    vector<Node>dict;
    while(1){
        dict.push_back(u);
        if(d[u.r][u.c][u.dir] == 0)break;
        u = p[u.r][u.c][u.dir];
    }
    dict.push_back(Node(r0,c0,dir));
    int cnt = 0;
    for(int i = dict.size() - 1; i >= 0; i--){
        if(cnt % 10 == 0)printf(" ");
        printf(" (%d,%d)",dict[i].r,dict[i].c);
        if(++cnt% 10 == 0)printf("\n");
    }
    if(dict.size() % 10 != 0) printf("\n");
}

void BFS(int r,int c,int dir){
    queue<Node>q;
    Node now,next;
    memset(d,-1,sizeof(d));//没访问
    now.r = r1,now.c = c1,now.dir = dir;
    d[now.r][now.c][now.dir] = 0;//起点
    q.push(now);
    while(!q.empty()){
        Node now = q.front();q.pop();
        if(now.r == r2 && now.c == c2){Print(now);flag = true;break;}
        for(int i = 0; i < 3; i++){
            next = Walk(now,i);
            if(Check(next,i) && has_edge[now.r][now.c][now.dir][i]){//注意是检查now是否可走
                d[next.r][next.c][next.dir] = d[now.r][now.c][now.dir] + 1;//路径长度
                p[next.r][next.c][next.dir] = now;//next的父节点是now
                q.push(next);
            }
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    char str[50],s1[50],s[50];
    char ch;
    while(scanf("%s",str) && str[0] != 'E'){
        flag = false;
        scanf("%d%d%s%d%d",&r0,&c0,s1,&r2,&c2);
        printf("%s\n",str);
        dir = dir_id(s1[0]);
        r1 = r0 + dr[dir];//走一步之后作为第一个点
        c1 = c0 + dc[dir];
        memset(has_edge,0,sizeof(has_edge));//可走的状态
        int r,c;
        while(scanf("%d%d",&r,&c) && r != 0){
            while(scanf("%s",s) && s[0] != '*'){
                for(int i = 1; i < strlen(s); i++){
                    has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = true;
                }
            }
        }
        BFS(r1,c1,dir);
        if(!flag)printf("  No Solution Possible\n");
    }
    return 0;
}
