//题目链接:https://vjudge.net/contest/185952#problem/C
//题目大意：已知C(n,m)=m!/(n!(m-n)!),求C(p,q)/C(r,s);
//解题思路：唯一分解定理的运用，首先求出10000以内的所有素数primes,然后用数组e表示当前结果
            //的唯一分解式中各个素数的指数


#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define maxn 10000
using namespace std;

typedef long long LL;
int prime[maxn];
bool flag[maxn];
int e[maxn];
int cnt;

void init(){
    cnt=0;
    memset(flag,true,sizeof(flag));
    flag[1]=false;
    for(int i=2;i<=10000;i++){
        if(flag[i]){
            prime[cnt++]=i;
            if(i*i<=10000){
                for(int j=i*i;j<=10000;j=j+i){
                    flag[j]=false;
                }
            }
        }
    }
}

void add_integer(int n,int d){

    for(int i=0;i<cnt;i++){
            while(n%prime[i]==0){
                n/=prime[i];
                e[i]+=d;
        }
        if(n==1)break;
    }
}

void add_faction(int n,int d){
    for(int i=1;i<=n;i++){
        add_integer(i,d);
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    int p,q,r,s;
    double ans;
    init();
    while(cin>>p>>q>>r>>s){
        memset(e,0,sizeof(e));
        add_faction(p,1);
        add_faction(q,-1);
        add_faction(p-q,-1);
        add_faction(r,-1);
        add_faction(s,1);
        add_faction(r-s,1);
        ans=1.0;
        for(int i=0;i<cnt;i++){
            ans*=pow(prime[i],e[i]);
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}
