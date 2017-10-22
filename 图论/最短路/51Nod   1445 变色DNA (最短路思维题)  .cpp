//题目链接:https://vjudge.net/contest/193113#problem/C
//题目大意：中文题
//解题思路：问题在于怎样设计边权，问题是要求经过最少多少次的改变一些点，来使得这个能达到n-1
            //我们把前面没有Y的且自身是Y的点的权值设置为0，把前面有k个Y（要想直接变到这个点就要把前面的删掉）的点（i，j）的权值设置为k
            //这样求出的最短路就是所求的答案

#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

#include<string>
#include<iostream>

const int maxn = 50+5;
const int INF = 1000000000;
using namespace std;

int d[maxn][maxn];
int n;

void floyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    char ch;
    while(T--){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            d[i][j]=INF;
        }
    }
        cin>>n;
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=0;j<n;j++){
                cin>>ch;
                if(ch=='Y'){
                    d[i][j]=k++;
                }
            }
        }
    floyd();
    if(d[0][n-1]==INF)cout<<"-1"<<endl;
    else cout<<d[0][n-1]<<endl;
    }
    return 0;
}


