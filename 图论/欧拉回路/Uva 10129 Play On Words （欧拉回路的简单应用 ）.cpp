//��Ŀ����:https://vjudge.net/contest/169966#problem/Q
//��Ŀ���⣺���Ǹ���һ���ַ����������ܲ��ܽ���Щ�ַ�������������Ҫ������β������
        //�������ܲ����ų�һ�����У�ʹ��ÿ�����ʵĵ�һ����ĸ����һ�����ʵ����һ����ĸ��ͬ
//����˼·����һ�����ŷ����·��һ��Ӧ�ã�����ŷ����·֮��ֻ����������ĳ���Ȳ���ͬ������������������յ㣬��Ҫ�ж����ͼ�ǲ�����ͨ�ģ�������DFS���߲��鼯

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100;
using namespace std;

int in[maxn],out[maxn];
bool vis[maxn];
int pa[maxn];
int ranks[maxn];
int res;  //�ж���ͨ�����ĸ���

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

//DFS���
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
        if((ans1 == 1 && ans2 == 1) || (ans1 == 0 && ans2 == 0))flag = true;  //ŷ����·����ŷ����·
        else flag = false;
        if(ans3 > 0)flag = false;  //ֻҪ�в����������ϵ�ľ��� ������ŷ����·����ŷ����·��
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

