//��Ŀ���ӣ�https://vjudge.net/contest/185952#problem/D
//��Ŀ���⣺��������n,������������������ʹ�����ǵ���С������Ϊn������Щ�����ĺ���С
//����˼·����n�ֽ⣬ÿ��ai^pi��Ϊһ������������ʱ����

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef long long LL;

int main(){
    //freopen("in.txt","r",stdin);
    LL n;
    int kase=0;
    while(cin>>n&&n){
        LL cnt=0;
        LL ans=0;
        LL x=n;
        for(LL i=2;i*i<=n;i++){
            LL temp=1;
            if(n%i==0){
                cnt++;
                while(n%i==0){
                    n/=i;
                    temp*=i;
                }
                ans+=temp;
            }
        }
        if(x==n){cout<<"Case "<<++kase<<": "<<x+1<<endl;continue;}
        else if(n!=1||cnt==1)ans+=n;
        cout<<"Case "<<++kase<<": "<<ans<<endl;
    }
    return 0;
}
