//题目链接：https://vjudge.net/contest/185952#problem/B
//题目大意：给出四个数，T,a,b,x1按照公式Xi=(a*(X[i-1])+b)%Mod生成序列，输入系列x1,x3,x5...输出x2,x4...
//解题思路：两种思路，第一种，可以直接枚举a,b看是否满足这个关系，
       //第二种,利用扩展欧几里得求得b（(x[2]=a*(x[1])+b)%Mod,x[3]=(a*(x[2])+b))Mod，再写出序列
       /*x3 = (a * (a * x1 + b) % 10001 + b ) % 10001;
       x3 = (a * (a * x1 + b) + b) % 10001;
       所以 x3 + 10001 * k = a * a * x1 + (a + 1) * b;
        x3 - a * a * x1 = (a + 1) * b + 10001 * (-k);*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#define maxn 10000+2
using namespace std;

const int Mod = 10001;
int x[maxn];

int main(){
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    for(int i=1;i<=2*T;i=i+2){
        cin>>x[i];
    }
    bool flag;
    for(int a=0;a<=10000;a++){
        for(int b=0;b<=10000;b++){
             flag=true;
            for(int i=2;i<=2*T;i=i+2){
                x[i]=(a*x[i-1]+b)%Mod;
                if(i<2*T&&x[i+1]!=(a*x[i]+b)%Mod){
                    flag=false;
                    break;
                }
            }
            if(flag)break;
        }
        if(flag)break;
    }
    for(int i=2;i<=2*T;i=i+2){
        cout<<x[i]<<endl;
    }
    return 0;
}




#include <iostream>
#include <string.h>
#include <stdio.h>
#define maxn 10000+2
using namespace std;

typedef long long LL;
const int Mod = 10001;
int x[maxn];

int exgcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
       x=1;
       y=0;
       return a;
    }
    else{
        int r=exgcd(b,a%b,x,y);
        int t=x;
        x=y;
        y=t-a/b*y;
        return r;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    for(int i=1;i<2*T;i=i+2){
        cin>>x[i];
    }
    for(LL a=0;a<Mod;a++){
        LL t=x[3]-a*a*x[1];
        LL b,k;
        LL d=exgcd(a+1,Mod,b,k);
        if(t%d!=0)continue;
        b=b*t/d;
        int flag=1;
        for(int i=2;i<=2*T;i=i+2){
            x[i]=(a*(x[i-1])+b)%Mod;
            if(i<2*T&& x[i+1] != (x[i]*a+b) % Mod){
                flag=0;
                break;
            }
        }
        if(flag)break;
    }

    for(int i=2;i<=2*T;i=i+2){
        cout<<x[i]<<endl;
    }
    return 0;
}
