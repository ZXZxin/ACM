//题目链接：https://vjudge.net/contest/185947#problem/B
//题目大意：有n个立方体，每种都有无穷多个，要求选一些立方体摞成一根尽量高的柱子，
        //使得每个立方体的底面长宽严格小于它下面的立方体的底面长宽
//解题思路：此题为矩形嵌套问题的变形

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 35
#define INF 0x3f3f3f
using namespace std;

int dp[maxn*3];

struct node {
   int len,wid,hel;
}m[maxn*3];

int cmp(struct node a,struct node b){
   if(a.len==b.len)return a.wid<b.wid;
   else return a.len<b.len;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    int kase=0;
    while(cin>>n&&n){
        int k=0;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            m[k].len=x>y?x:y;
            m[k].wid=x<y?x:y;
            m[k++].hel=z;
            m[k].len=x>z?x:z;
            m[k].wid=x<z?x:z;
            m[k++].hel=y;
            m[k].len=y>z?y:z;
            m[k].wid=y<z?y:z;
            m[k++].hel=x;
        }
        sort(m,m+k,cmp);
        int ans=-1;
        for(int i=0;i<k;i++){
            dp[i]=m[i].hel;
            for(int j=0;j<i;j++){
                if(m[j].len<m[i].len&&m[j].wid<m[i].wid&&dp[i]<dp[j]+m[i].hel)
                dp[i]=dp[j]+m[i].hel;
            }
        ans=max(ans,dp[i]);
        }
        cout<<"Case "<<++kase<<": maximum height = "<<ans<<endl;
    }
    return 0;
}
