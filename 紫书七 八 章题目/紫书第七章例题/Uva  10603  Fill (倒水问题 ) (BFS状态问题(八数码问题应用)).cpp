//题目链接:https://vjudge.net/contest/171111#problem/H
//题目大意:就是给你a,b,c三个瓶子的容量,只有c中装满了水,a,b,c没有刻度,要你量出d升水,如果量不出,求最接近d升水时的倒的最小的水量以及d
//解题思路: 这个是BFS求最短路的状态问题(八数码问题),这里注意到vis本来是三维的,但是如果前两个a,b确定(相同)的话,就可以判断
           //由于是求目前倒的水量最少,所以选择优先队列
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

const int maxn = 200 + 10;
using namespace std;

bool vis[maxn][maxn];
int cap[3],ans[maxn];

struct Node{
    int v[3];
    int dist;//到目前状态倒的总水量
    bool operator < (const Node& rhs)const{ //重载<运算符
        return dist > rhs.dist;
    }
};

void update_ans(const Node& u){
    for(int i = 0; i < 3; i++){
        int d = u.v[i];  //这里要把每一个状态的 三个瓶子的 ans算出来,而不是只算一个,因为等下要求d
        if(ans[d] == -1 || u.dist < ans[d])ans[d] = u.dist;
    }
}

void BFS(int a,int b,int c,int d){
    cap[0] = a,cap[1] = b,cap[2] = c;
    memset(vis,false,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<Node>q;

    Node Now,Next;
    Now.dist = 0,Now.v[0] = 0,Now.v[1] = 0,Now.v[2] = c;
    vis[Now.v[0]][Now.v[1]] = true;
    q.push(Now);
    while(!q.empty()){
        Now = q.top();q.pop();
        update_ans(Now);
        if(ans[d] != -1)break;  //已经更新过(已经达到)就不用了
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if( i != j ){
                    if(Now.v[j] == cap[j] || Now.v[i] == 0)continue;
                    int amount = min(cap[j],Now.v[i] + Now.v[j]) - Now.v[j];  //算出是倒满v[j],还是倒空v[j];

                    memcpy(Next.v,Now.v,sizeof(Now.v));
                    Next.dist = Now.dist + amount;
                    Next.v[i] -= amount;
                    Next.v[j] += amount;

                    if(!vis[Next.v[0]][Next.v[1]]){  //vis只有二维的原因是  如果前两个杯子的水相同,则第三个杯子的水也相同,所以只要看前两个杯子
                        vis[Next.v[0]][Next.v[1]] = true;
                        q.push(Next);
                    }
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        BFS(a,b,c,d);
        for(int i = d; i >= 0; i--){//前提是保证接近d
            if(ans[i] != -1){printf("%d %d\n",ans[i],i);break;}  //注意不要把break写在外面

        }
    }
    return 0;
}



//后来刘汝佳的改进:
//增加dist[][]二维数组再次判重  以及  dijkstra算法

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

const int maxn = 200 + 10;
using namespace std;

bool vis[maxn][maxn];
int dist[maxn][maxn],cap[3],ans[maxn];//dist数组其实还是记录每一个状态中的u.dist

struct Node{
    int v[3];
    int dist;//到目前状态倒的总水量
    bool operator < (const Node& rhs)const{ //重载<运算符
        return dist > rhs.dist;
    }
};

void update_ans(const Node& u){
    for(int i = 0; i < 3; i++){
        int d = u.v[i];  //这里要把每一个状态的 三个瓶子的 ans算出来,而不是只算一个,因为等下要求d
        if(ans[d] < 0 || u.dist < ans[d])ans[d] = u.dist;
    }
}

void BFS(int a,int b,int c,int d){
    cap[0] = a,cap[1] = b,cap[2] = c;
    memset(vis,false,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    memset(dist,-1,sizeof(dist));
    priority_queue<Node>q;

    Node Now,Next;
    Now.dist = 0,Now.v[0] = 0,Now.v[1] = 0,Now.v[2] = c;
    dist[Now.v[0]][Now.v[1]] = 0;
    q.push(Now);
    while(!q.empty()){
        Now = q.top();q.pop();
        if(vis[Now.v[0]][Now.v[1]])continue;
        vis[Now.v[0]][Now.v[1]] = true;
        update_ans(Now);
        if(ans[d] >= 0)break;  //已经更新过(已经达到)就不用了
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if( i != j ){
                    if(Now.v[j] == cap[j] || Now.v[i] == 0)continue;
                    int amount = min(cap[j],Now.v[i] + Now.v[j]) - Now.v[j];  //算出是倒满v[j],还是倒空v[j];

                    memcpy(&Next,&Now,sizeof(Now));
                    Next.dist = Now.dist + amount;
                    Next.v[i] -= amount;
                    Next.v[j] += amount;

                    if(dist[Next.v[0]][Next.v[1]] < 0  || dist[Next.v[0]][Next.v[1]] > Next.dist){  //vis只有二维的原因是  如果前两个杯子的水相同,则第三个杯子的水也相同,所以只要看前两个杯子
                        dist[Next.v[0]][Next.v[1]] = Next.dist;
                        q.push(Next);
                    }
                }
            }
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a,b,c,d;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        BFS(a,b,c,d);
        for(int i = d; i >= 0; i--){  //前提是保证接近d
            if(ans[i] >= 0){
                printf("%d %d\n",ans[i],i);
                break;
            }
        }
    }
    return 0;
}
