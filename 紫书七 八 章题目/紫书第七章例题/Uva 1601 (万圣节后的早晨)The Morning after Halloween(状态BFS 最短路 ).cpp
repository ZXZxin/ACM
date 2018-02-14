//题目链接:https://vjudge.net/contest/171111#problem/I
//题目大意: 就是给你一个迷宫,给你最多a,b,c，要你找到相应的A,B,C需要的步数(注意两个鬼不能占同一个位置,也不能在一步之内交换位置)
/*解题思路:添加虚拟节点，使它更方便BFS。用二进制映射状态，方便入队和出队。使用数组来变换方向
          另外，假如你没有进行优化直接用原图BFS，那么肯定是会超时的，在这里就有一种优化方法。
          可以将原图存好后把字母和空格单独剔出来，因为‘#’它是不访问的 就是把非'#'的地方建一个图*/
//这题很纳闷: 输入问题一直没有解决
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;
const int maxn = 16 * 16;

struct Node{
    int a,b,c;
    Node(){};
    Node(int a,int b,int c):a(a),b(b),c(c){}
};

char maze[16][16],id[16][16];  //一开始的迷宫 和 自己键的迷宫
int deg[maxn - 60]; //其实没有必要maxn大部分是#(障碍)
int G[maxn][5]; //5个方向
int s[3],t[3]; //start,end;
int x[maxn],y[maxn]; //记录 建的图的 每个点的 x , y坐标
int d[maxn][maxn][maxn];
int dir[5][2] = {{-1,0},{0,1},{1,0},{0,-1},{0,0}};

int ID(int a,int b,int c){
    return (a << 16) | (b << 8) | c;
}

bool is_conflict(int a,int b,int a2,int b2){
    return a2 == b2 || (a == b2 && b == a2);
}

void BFS(){
    //queue<int>q;
    queue<Node>q;
    Node u,u2;
    u.a = s[0]; u.b = s[1]; u.c = s[2];
    q.push(u);
    //q.push(ID(s[0],s[1],s[2]));
    memset(d,-1,sizeof(d));
    d[s[0]][s[1]][s[2]] = 0;
    while(!q.empty()){
        /*int */u = q.front();q.pop();
        //int a = (u>>16)&0xff, b = (u>>8)&0xff, c = u&0xff;
        int a = u.a, b = u.b, c = u.c;
        if(a == t[0] && b == t[1] && c == t[2]){printf("%d\n",d[a][b][c]);return;}
        for(int i = 0; i < deg[a]; i++){
            int a2 = G[a][i];
            for(int j = 0; j < deg[b]; j++){
                int b2 = G[b][j];
                if(is_conflict(a,b,a2,b2))continue;
                for(int k = 0; k < deg[c]; k++){
                    int c2 = G[c][k];
                    if(is_conflict(a,c,a2,c2))continue;
                    if(is_conflict(b,c,b2,c2))continue;
                    if(d[a2][b2][c2] != -1)continue;
                    d[a2][b2][c2] = d[a][b][c] + 1;
                    //q.push(ID(a2,b2,c2));
                    q.push(Node(a2,b2,c2));
                }
            }
        }
    }
    printf("-1\n");
}

int main(){
    int w,h,n;
    while(scanf("%d%d%d\n",&w,&h,&n) && n){ //注意"\n" 等价于 getchar()的作用
        for(int i = 0; i < h; i++)fgets(maze[i],20,stdin);//读取最大长度为20的字符串

        int cnt = 0; //cnt为图的结点数
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)if(maze[i][j] != '#'){
                x[cnt] = i; y[cnt] = j; id[i][j] = cnt;
                if(islower(maze[i][j]))  s[maze[i][j] - 'a'] = cnt; //记录初始位置
                else if(isupper(maze[i][j]))  t[maze[i][j] - 'A'] = cnt;
                cnt++;
        }
        memset(deg,0,sizeof(deg));
        for(int i = 0; i < cnt; i++)
            for(int j = 0; j < 5; j++){
                int xx = x[i] + dir[j][0];
                int yy = y[i] + dir[j][1];
                if(maze[xx][yy] != '#')G[i][deg[i]++] = id[xx][yy];
        }
        if(n <= 2) { deg[cnt] = 1; G[cnt][0] = cnt; s[2] = t[2] = cnt++; } //增加虚拟结点
        if(n <= 1) { deg[cnt] = 1; G[cnt][0] = cnt; s[1] = t[1] = cnt++; }
        BFS();
    }
    return 0;
}
