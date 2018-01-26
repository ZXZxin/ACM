//题目连接：http://poj.org/problem?id=1041
//题目大意：就是每行 三个数x,y,z代表 x,y路口通过 z 街道 相连 要你从数字最小的地方开始找一条欧拉回路 并输出
//解题思路：DFS的时候要 遍历每个街道，而且map[x][z] = y 一开始也是没有想到

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

const int maxn = 2000 + 5;
using namespace std;

int vis[maxn];
int map[50][maxn];
int in[maxn];
int maxx,minn,street_cnt;
stack<int>s;

void DFS(int u){
    for(int i = 1; i <= street_cnt; i++){ //遍历每条街
        if(map[u][i] && !vis[i]){
            vis[i] = 1;
            DFS(map[u][i]); //DFS u 通过 i 能到达那个点 即 map[u][i]
            s.push(i);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int x,y,z;
    while(scanf("%d %d",&x,&y) != EOF && (x || y)){
        scanf("%d",&z);
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        memset(in,0,sizeof(in));
        while(!s.empty())s.pop();
        minn = x,maxx = x; //记录路口的最小编号和最大编号
        if(y < x)minn = y;
        if(y > x)maxx = y;
        map[x][z] = y,map[y][z] = x;//代表 x 通过 z 能到达 y
        in[x]++,in[y]++;
        street_cnt = 1;  //记录街道的数量
        while(true){
            scanf("%d%d",&x,&y);
            if(x == 0 && y == 0)break;
            scanf("%d",&z);
            if(x < minn)minn = x;
            if(y < minn)minn = y;
            if(x > maxx)maxx = x;
            if(y > maxx)maxx = y;
            map[x][z] = y,map[y][z] = x;
            in[x]++,in[y]++;
            street_cnt++;
        }
        bool flag = true;
        DFS(minn);
        for(int i = 1; i <= maxx; i++)if(in[i]%2 != 0){  //欧拉回路的条件之一
           flag = false;break;
        }
        for(int i = 1; i <= street_cnt; i++)if(!vis[i]){  //判断是不是连通的
            flag = false;break;
        }
        if(!flag)printf("Round trip does not exist.\n");
        else {
            while(s.size() != 1){
                printf("%d ",s.top());
                s.pop();
            }
            printf("%d\n",s.top());
        }
    }
    return 0;
}
