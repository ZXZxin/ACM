//��Ŀ���ӣ�https://vjudge.net/contest/185952#problem/E
//��Ŀ���⣺�ж��ٶ�������a,b������1<=b<=a<=n,��gcd(a,b)=a XOR b
//����˼·��a XOR b=c,��a XOR c=b,���Կ���ö��a��c,Ȼ�����b=a XOR c�������֤gcd(a,b)=c
           //,,��������з���c=a-b,�õķ�����ֱ�Ӽ���b=a-c,��֤�Ƿ���c=a XOR b

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
