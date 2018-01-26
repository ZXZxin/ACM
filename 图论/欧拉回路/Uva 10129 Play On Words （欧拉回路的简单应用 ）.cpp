//题目链接:https://vjudge.net/contest/169966#problem/Q
//题目大意：就是给你一组字符串，问你能不能将这些字符串连接起来，要求是首尾相连，
        //就是问能不能排成一个序列，使得每个单词的第一个字母和上一个单词的最后一个字母相同
//解题思路：这一题就是欧拉回路的一个应用，有向欧拉道路之多只能有两个点的出入度不相同，这两个点就是起点和终点，还要判断这个图是不是连通的，可以用DFS或者并查集

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100;
using namespace std;

int in[maxn],out[maxn];
bool vis[maxn];
int pa[maxn];
int ranks[maxn];
int res;  //判断连通分量的个数

void init(){
    for(int i = 0; i < 26; i++) {
        pa[i] = i;
        ranks[i] = 0;
    }
}
int Find(int x){
    return pa[x] == x ? x : Find(pa[x]);
}
void Union(int x,int y){
    int xx = Find(x);
    int yy = Find(y);
    if(xx == yy)return ;
    if(ranks[xx] < ranks[yy])pa[xx] = yy;
    else{
        pa[yy] = xx;
        if(ranks[yy] == ranks[xx])ranks[xx]++;
    }
    res--;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    char s[2000];
    scanf("%d",&T);
    while(T--){
        init();
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        bool flag = true;
        res = 26;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%s",s);
            int len = strlen(s);
            int ru = s[0] - 'a';
            int chu = s[len - 1] - 'a';
            in[ru]++;
            out[chu]++;
            vis[ru] = vis[chu] = 1;
            Union(ru,chu);
        }
        int ans1 = 0,ans2 = 0,ans3 = 0;
        for(int i = 0; i < 26; i++){
            if(in[i] == out[i])continue;
            else if(in[i] == out[i] + 1)ans1++;
            else if(out[i] == in[i] + 1)ans2++;
            else ans3++;
        }
        if((ans1 == 1 && ans2 == 1) || (ans1 == 0 && ans2 == 0))flag = true;
        else flag = false;
        if(ans3 > 0)flag = false;
        for(int i = 0; i < 26; i++){
            if(!vis[i]) res--;
        }
        if(res != 1)flag = false;
        if(flag)printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}

//DFS求解
/*
#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100;
using namespace std;

int G[maxn][maxn],in[maxn],out[maxn];
bool vis[maxn];

void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < 26; i++){
        if(!vis[i] && G[u][i]) dfs(i);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    char s[2000];
    scanf("%d",&T);
    while(T--){
        memset(vis,1,sizeof(vis));
        memset(G,0,sizeof(G));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        bool flag = true;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%s",s);
            int len = strlen(s);
            int ru = s[0] - 'a';
            int chu = s[len - 1] - 'a';
            G[ru][chu] = 1;
            in[ru]++;
            out[chu]++;
            vis[ru] = vis[chu] = 0;
        }
        int p = 0;
        int ans1 = 0,ans2 = 0,ans3 = 0;
        for(int i = 0; i < 26; i++){
            if(in[i] == out[i])continue;
            else if(in[i] == out[i] + 1){ans1++;p = i;}
            else if(out[i] == in[i] + 1)ans2++;
            else ans3++;
        }
        if((ans1 == 1 && ans2 == 1) || (ans1 == 0 && ans2 == 0))flag = true;  //欧拉道路或者欧拉回路
        else flag = false;
        if(ans3 > 0)flag = false;  //只要有不满足这个关系的就是 不满足欧拉道路或者欧拉回路的
        dfs(p);
        for(int i = 0; i < 26; i++){
            if(!vis[i])flag = false;
        }
        if(flag)printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
*/

