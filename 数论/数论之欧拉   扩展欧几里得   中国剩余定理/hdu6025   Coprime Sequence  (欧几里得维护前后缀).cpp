//题目链接：http://acm.split.hdu.edu.cn/showproblem.php?pid=6025
//题目大意：给你一组数，要求去掉其中一个数，使得他们的gcd最大
//解题思路：求前缀gcd和后缀gcd。然后枚举每一个数，求每一个数的前缀gcd与后缀gcd的gcd，取最大值

#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn = 1e5+20;//重要
using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int pre[maxn];
int nxt[maxn];
int a[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        pre[1]=a[1];
        for(int i=2;i<=n;i++)pre[i]=gcd(pre[i-1],a[i]);
        nxt[n]=a[n];
        for(int i=n-1;i>=1;i--)nxt[i]=gcd(nxt[i+1],a[i]);
        int ans=max(nxt[2],pre[n-1]);
        for(int i=2;i<n;i++){
            ans=max(ans,gcd(pre[i-1],nxt[i+1]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
