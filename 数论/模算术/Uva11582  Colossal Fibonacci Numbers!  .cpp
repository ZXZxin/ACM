//题目链接：https://vjudge.net/contest/185952#problem/A
//题目大意: 计算f(a的b次方)%n,f(i)=f(i-1)+f(i-2)
//解题思路：用取模，发现有循环节
#include <iostream>
#include <math.h>
#include <stdio.h>
#define maxn 1000
using namespace std;

typedef unsigned long long LL;

int f[maxn*maxn+5];

int pow_mod(LL a,LL b,int m){
    if(b==0)return 1;
    LL x=pow_mod(a,b/2,m);
    x=(LL)x*x%m;
    if(b%2==1)x=x*a%m;
    return x;
}

int pow(LL a,LL p,int Mod)
{
    int ans=1;
    while(p)
    {
        if(p & 1)ans*=a,ans%=Mod;
        a*=a;a%=Mod;
        p>>=1;
    }
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    LL a,b;
    int n,T,res;
    cin>>T;
    while(T--){
        cin>>a>>b>>n;
        if(!a||n==1){cout<<0<<endl;continue;}
        f[0]=1;f[1]=1;
        for(int i=2;i<=n*n+10;i++){
        f[i]=f[i-2]+f[i-1];
        f[i]=f[i]%n;
        if(f[i]==f[1]&&f[i-1]==f[0]){res=i-1;break;}
        }
        int ans=pow_mod(a%res,b,res);
        cout<<f[ans-1]<<endl;
    }
    return 0;
}
