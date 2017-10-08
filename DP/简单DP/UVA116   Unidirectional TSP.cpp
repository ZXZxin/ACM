//题目链接：https://vjudge.net/contest/185947#problem/D
//题目大意：给你一个矩阵，从第一列的任何一个位置出发，每次可以往右，右上，右下走一格
           //且矩阵是环形的，要求经过的整数之和最小，输出路径上每列的行号，多解时输出字典序最小的
//解题思路：设dp[i][j]表示从格子（i,j）出发到最后一列的最小开销，设计状态即可

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define maxn 100+5
#define INF 0x3f3f3f3f
using namespace std;

int a[maxn][maxn];
int dp[maxn][maxn];
int nexts[maxn][maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    while(cin>>m>>n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
    int ans=INF,first=0;
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<m;i++){
            if(j==n-1)dp[i][j]=a[i][j];
            else{
                int rows[3]={i,i-1,i+1};
                if(i==0)rows[1]=m-1;
                if(i==m-1)rows[2]=0;
                sort(rows,rows+3);
                dp[i][j]=INF;
                for(int k=0;k<3;k++){
                    int v=dp[rows[k]][j+1]+a[i][j];
                    if(v<dp[i][j]){dp[i][j]=v,nexts[i][j]=rows[k];}
                }
            }
            if(j==0&&dp[i][j]<ans){ans=dp[i][j];first=i;}
        }
    }
    cout<<first+1;
    for(int i=nexts[first][0],j=1;j<n;i=nexts[i][j],j++){
        cout<<" "<<i+1;
    }
    cout<<endl<<ans<<endl;
    }
    return 0;
}
