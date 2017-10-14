//题目链接：http://poj.org/problem?id=1061
//题目大意：中文题，给出青蛙A，B的起点坐标,以及跳跃距离m,n以及环的长度L，求什么时候能相遇
/*解题思路：设经过T次跳跃相遇,得到(n-m)*T-P*L==x-y 我们设a=(n-m),b=L,c=x-y,T=x,P=y.
             于是便得到ax+by==c，直接利用欧几里得扩展定理可以得到一组x,y但是这组x,y不一定是符合条件的最优解，
             首先,当gcd(a,b)不能整除c的时候是无解的，当c能整除gcd(a,b)时，把x和y都要变为原来的c/gcd(a,b)倍，
             我们知道它的通解为x0+b/gcd(a,b)*t要保证这个解是不小于零的最小的数，
             我们先计算当x0+b/gcd(a,b)*t=0时的t值，
             此时的t记为t0=-x0/b/gcd(a,b)（整数除法），代入t0如果得到的x小于零再加上一个b/gcd(a,b)就可以了*/


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
