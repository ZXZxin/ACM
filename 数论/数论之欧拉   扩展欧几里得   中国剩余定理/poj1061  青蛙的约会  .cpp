//��Ŀ���ӣ�http://poj.org/problem?id=1061
//��Ŀ���⣺�����⣬��������A��B���������,�Լ���Ծ����m,n�Լ����ĳ���L����ʲôʱ��������
/*����˼·���辭��T����Ծ����,�õ�(n-m)*T-P*L==x-y ������a=(n-m),b=L,c=x-y,T=x,P=y.
             ���Ǳ�õ�ax+by==c��ֱ������ŷ�������չ������Եõ�һ��x,y��������x,y��һ���Ƿ������������Ž⣬
             ����,��gcd(a,b)��������c��ʱ�����޽�ģ���c������gcd(a,b)ʱ����x��y��Ҫ��Ϊԭ����c/gcd(a,b)����
             ����֪������ͨ��Ϊx0+b/gcd(a,b)*tҪ��֤������ǲ�С�������С������
             �����ȼ��㵱x0+b/gcd(a,b)*t=0ʱ��tֵ��
             ��ʱ��t��Ϊt0=-x0/b/gcd(a,b)������������������t0����õ���xС�����ټ���һ��b/gcd(a,b)�Ϳ�����*/


#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

LL exgcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    LL d=exgcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

int main(){
    //freopen("in.txt","r",stdin);
    LL x,y,m,n,L,T,P;
    while(cin>>x>>y>>m>>n>>L){
        LL a,b,c;
        a=n-m;
        b=L;
        c=x-y;
        LL d=exgcd(a,b,T,P);
        if(c%d!=0){cout<<"Impossible"<<endl;continue;}

        T=T*(c/d);
        P=P*(c/d);

        LL k=T*d/b;
        k=T-k*b/d;
        if(k<0)k=k+b/d;
        cout<<k<<endl;

    }
    return 0;
}
