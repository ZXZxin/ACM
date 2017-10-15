//题目链接：https://vjudge.net/contest/185952#problem/E
//题目大意：有多少对整数（a,b）满足1<=b<=a<=n,且gcd(a,b)=a XOR b
//解题思路：a XOR b=c,则a XOR c=b,所以可以枚举a和c,然后求出b=a XOR c，最后验证gcd(a,b)=c
           //,,计算过程中发现c=a-b,好的方法是直接计算b=a-c,验证是否有c=a XOR b

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int maxn = 30000000;
using namespace std;

int cnt[maxn+5],sum[maxn+5];

void init(){
   memset(cnt,0,sizeof(cnt));
   for(int c=1;c<=maxn;c++){
            for(int a=2*c;a<=maxn;a=a+c){
                int b=a-c;
                if(c==(a^b))cnt[a]++;
            }
        }
    sum[0]=0;
    for(int i=1;i<=maxn;i++)sum[i]=sum[i-1]+cnt[i];
}

int main()
{
    //freopen("in.txt","r",stdin);
    int T,n,kase=0;
    init();
    cin>>T;
    while(T--){
        cin>>n;
        cout<<"Case "<<++kase<<": "<<sum[n]<<endl;
    }
    return 0;
}
