//��Ŀ���ӣ�http://acm.split.hdu.edu.cn/status.php
//��Ŀ���⣺��01������ȫ����
//����˼·��ģ��01����


#include <iostream>
#include <algorithm>
const int maxn=1000+5;
using namespace std;

int w[maxn];
int v[maxn];
int dp[maxn][maxn];

int main(){
    int T;
    int n,C;
    cin>>T;
    while(T--){
        cin>>n>>C;
        for(int i=1;i<=n;i++)cin>>w[i];
        for(int i=1;i<=n;i++)cin>>v[i];
        for(int i=1;i<=n;i++){
            for(int j=0;j<=C;j++){
                dp[i][j]=(i==1?0:dp[i-1][j]);
                if(j>=v[i]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-v[i]]+w[i]);
                }
            }
        }
        cout<<dp[n][C]<<endl;
    }
    return 0;
}




#include <iostream>
#include <algorithm>
const int maxn=1000+5;
using namespace std;

int w[maxn];
int v[maxn];
int dp[maxn][maxn];

int main(){
    int T;
    int n,C;
    cin>>T;
    while(T--){
        cin>>n>>C;
        for(int i=1;i<=n;i++)cin>>w[i];
        for(int i=1;i<=n;i++)cin>>v[i];
        for(int i=n;i>=1;i--){
            for(int j=0;j<=C;j++){
                dp[i][j]=(i==n?0:dp[i+1][j]);
                if(j>=v[i]){
                    dp[i][j]=max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
                }
            }
        }
        cout<<dp[1][C]<<endl;
    }
    return 0;
}


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
const int maxn=1000+5;
using namespace std;

int w[maxn];
int v[maxn];
int dp[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    int n,C;
    cin>>T;
    while(T--){
        cin>>n>>C;
        for(int i=1;i<=n;i++)cin>>w[i];
        for(int i=1;i<=n;i++)cin>>v[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=C;j>=0;j--){
                if(j>=v[i]){
                    dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
                }
            }
        }
        cout<<dp[C]<<endl;
    }
    return 0;
}




