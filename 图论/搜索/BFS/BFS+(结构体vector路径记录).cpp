//路径记录
//一定注意djr方向数组中的,x对应上下，减代表向上

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>
#include <string>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;
const int maxn = 100 + 10;

int n,m;
bool flag;
int map[maxn][maxn];
bool vis[maxn][maxn];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};//对应上，右，下，左
int start_x, start_y;
int end_x, end_y;//起始点

struct Road {//路径记录
    int x,y,d;//d表示方向
    Road() {}
    Road(int a,int b,int c):x(a),y(b),d(c) {}
};

struct node {//节点类型
    int x,y;
    vector<Road> v;//记录路径的结构体
};

bool check(node u) {
    if (!vis[u.x][u.y] && u.x >= 0 && u.x < n && u.y >= 0 && u.y < m && map[u.x][u.y] != 1)
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
        if (now.x == end_x && now.y == end_y) {
            for(int i = 0; i < now.v.size(); i++){
                if(now.v[i].d == 0)printf("(%d,%d) 然后向上走\n",now.v[i].x,now.v[i].y);
                //注意点：dir[x][y] x是行数x的变化是上下的变化不是左右的变化，区别于坐标轴,杜绝思维定势 ,y是列数y的变化,是左右的变化
                else if(now.v[i].d == 1)printf("(%d,%d) 然后向右走\n",now.v[i].x,now.v[i].y);
                else if(now.v[i].d == 2)printf("(%d,%d) 然后向下走\n",now.v[i].x,now.v[i].y);
                else if(now.v[i].d == 3)printf("(%d,%d) 然后向左走\n",now.v[i].x,now.v[i].y);
                else if(now.v[i].d == -1)printf("(%d,%d) 到达终点\n",now.v[i].x,now.v[i].y);
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
    freopen("in.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) {
        flag = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[i][j]);
            }
        }
        printf("请输入起始点:\n");
        scanf("%d%d", &start_x, &start_y);
        printf("请输入结束点:\n");
        scanf("%d%d",&end_x, &end_y);
        BFS(start_x, start_y);
    }
    return 0;
}
/*
测试数据
3 4
0 0 0 0
1 1 0 1
0 1 0 0
0 0
2 3
*/

