//题目链接 : https://vjudge.net/contest/216415#problem/D
//题目大意 : 有一个色子,给你四张不同视图的图片,要你根据这些图片,先确定色子每面的数字
           //然后给你一个数n,要你经过一系列的翻转筛子,每次翻转筛子的一面,和就加上那一面的数字
           //要你求最短的步数达到n
//解题思路 : BFS求解,注意vis数组标记的是sum的值
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100000 + 10;
typedef long long LL;

struct Node {
    int id,step,sum;
    Node(){}
    Node(int id,int step,int sum):id(id),step(step),sum(sum){}
};

int n,Map[8][8];
bool vis[maxn];

void BFS(int s){
    if(n == 1){printf("-1\n");return ;} //输入1时输出-1
    Node Now,Next;
    Now.id = 1,Now.sum = 0,Now.step = 0;
    vis[0] = true;
    queue<Node>q;
    q.push(Now);
    while(!q.empty()){
        Now = q.front();q.pop();
        if(Now.sum == n){printf("%d\n",Now.step); return;}
        for(int i = 1; i <= 6; i++){
            if(Map[Now.id][i]){
                int newSum = Now.sum + Map[Now.id][i];
                if(vis[newSum])continue;
                vis[newSum] = true;
                q.push(Node(i,Now.step+1,newSum));
            }
        }
    }
    printf("-1\n");
}


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(Map,0,sizeof(Map));
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= 6; i++){
            for(int j = 1; j <= 6; j++){
                if(i + j != 7 && i != j)Map[i][j] = j;
            }
        }
        BFS(1);
    }
    return 0;
}
