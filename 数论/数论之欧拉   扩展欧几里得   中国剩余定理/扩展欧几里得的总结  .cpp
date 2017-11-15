//扩展欧几里得的学习
/*
    （2）
    基本算法：对于不完全为 0 的非负整数 a，b，gcd（a，b）表示 a，b 的最大公约数，必然存在整数对 x，y ，使得 gcd（a，b）=ax+by。
证明：设 a>b。
　　1，显然当 b=0，gcd（a，b）=a。此时 x=1，y=0；
　　2，ab!=0 时
　　设 ax1+by1=gcd(a,b);
　　bx2+(a mod b)y2=gcd(b,a mod b);
　　根据朴素的欧几里德原理有 gcd(a,b)=gcd(b,a mod b);
　　则:ax1+by1=bx2+(a mod b)y2;
　　即:ax1+by1=bx2+(a-(a/b)*b)y2=ay2+bx2-(a/b)*by2;
　　根据恒等定理得：x1=y2; y1=x2-(a/b)*y2;    //关键
    这样我们就得到了求解 x1,y1 的方法：x1，y1 的值基于 x2，y2.
　  上面的思想是以递归定义的，因为 gcd 不断的递归求解一定会有个时候 b=0，所以递归可以结束。
*/
/*（2）使用扩展欧几里德算法解决不定方程的办法：
    对于不定整数方程pa+qb=c，若 c mod Gcd(p, q)=0,则该方程存在整数解，否则不存在整数解。
    上面已经列出找一个整数解的方法，在找到p * a+q * b = Gcd(p, q)的一组解p0,q0后，p * a+q * b = Gcd(p, q)的其他整数解满足：
    p = p0 + b/Gcd(p, q) * t
    q = q0 - a/Gcd(p, q) * t(其中t为任意整数)
    至于pa+qb=c的整数解，只需将p * a+q * b = Gcd(p, q)的每个解乘上 c/Gcd(p, q) 即可。
    在找到p * a+q * b = Gcd(a, b)的一组解p0,q0后，应该是得到p * a+q * b = c的一组解p1 = p0*(c/Gcd(a,b)),q1 = q0*(c/Gcd(a,b))，
    p * a+q * b = c的其他整数解满足：
    p = p1 + b/Gcd(a, b) * t
    q = q1 - a/Gcd(a, b) * t(其中t为任意整数)
    p 、q就是p * a+q * b = c的所有整数解。
*/

#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

const int maxn = 10000+10;

int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);  //d 就是gcd(a,b)
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

bool linear_equation(int a,int b,int c,int &x,int &y)
{
    int d = exgcd(a,b,x,y);  //求出a*x+b*y = gcd(a,b)的一组解
    cout<<"a*x + b*y = gcd(a,b)的一些解是"<<endl;
    cout<<x<<" "<<y<<endl;
    for(int t = 2; t < 10; t++){   //输出 a*x + b*y = gcd(a,b)的其他一些解
        int x1 = x + b/d*t;
        int y1 = y - a/d*t;
        cout<<x1<<" " <<y1<<endl;
    }
    cout<<endl<<endl;
    if(c%d)
        return false;
    int k = c/d;    //上述解乘以 c/gcd(a,b)就是 a*x +b*y = c的解
    x*=k; y*=k;    //求得的只是其中一组解
    return true;
}

int main(){
    //freopen("in.txt","r",stdin)；
    int a = 6,b = 15,c = 9;  //求解 6*x + 15*y = 9的解
    int x,y;
    int d = exgcd(a,b,x,y);
    if(!linear_equation(a,b,c,x,y))cout<<"无解"<<endl;
    cout<<"a*x + b*y = c的一些解是"<<endl;
    cout<<x<<" "<<y<<endl;
    for(int t = 2; t < 10; t++){  //输出其他的一些解
        int x1 = x + b/d*t;
        int y1 = y - a/d*t;
        cout<<x1<<" "<<y1<<endl;
    }
    return 0;
}
