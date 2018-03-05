//选择不相交区间问题(贪心法)
//题目链接 : http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=966
//题目大意 : 就是给一系列的区间，要求区间个数最多，且这些区间不相交，需要注意的是这些区间都是闭区间。
//解题思路 : 贪心策略一定选择第一个，然后向后遍历，每次更换前面的node[i].y(具体看刘汝佳的书第八章)

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 10;

struct Node{
    int x,y;
    bool operator < (const Node & rhs) const{
        return y < rhs.y || (y == rhs.y && x < rhs.x);
    }
}node[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int n,kase = 0;
    int path[maxn]; //记录区间
    while(scanf("%d",&n) != EOF){
        int temp; //用于下面的 "坑"
        for(int i = 0; i < n; i++){
            scanf("%d%d",&node[i].x,&node[i].y);
            if(node[i].x > node[i].y){  //坑
                temp = node[i].x;
                node[i].x = node[i].y;
                node[i].y = temp;
            }
        }
        sort(node,node+n);
        int End = node[0].y;  //先选择第一个
        int sum = 1; //记录个数,第一个必须选
        for(int i = 1; i < n; i++){
            if(node[i].x > End){
                path[sum++] = i;
                End = node[i].y;
            }
        }
        //printf("%d %d\n",node[0].x,node[0].y);
        //for(int i = 1; i < sum; i++)printf("%d %d\n",node[path[i]].x,node[path[i]].y); //输出区间
        printf("Case %d:\n",++kase);
        printf("%d.\n",sum);
    }
    return 0;
}
