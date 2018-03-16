//题目链接 : https://www.patest.cn/contests/gplt/L1-033
//解题思路 : 注意vis的巧妙使用


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int maxn = 10000 + 10;
using namespace std;

bool check(int n,int m){
    int vis[10];
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < 4; i++){
        vis[n%10] = 1;
        n /= 10;
    }
    int cnt = 0;
    for(int i = 0; i < 10; i++)if(vis[i])cnt++;
    if(cnt == m)return true;
    return false;
}

int main(){
    // freopen("in.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int ansi = 0;
        int sum = 0;
        for(int i = n; i <= 3020; i++){
            sum++;
            if(check(i,m)){
                ansi=i;
                break;
            }
        }
        printf("%d %04d\n",sum-1,ansi);
    }
    return 0;
}
