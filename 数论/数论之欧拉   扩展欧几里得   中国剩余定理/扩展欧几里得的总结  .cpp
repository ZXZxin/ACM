//��չŷ����õ�ѧϰ
/*
    ��2��
    �����㷨�����ڲ���ȫΪ 0 �ķǸ����� a��b��gcd��a��b����ʾ a��b �����Լ������Ȼ���������� x��y ��ʹ�� gcd��a��b��=ax+by��
֤������ a>b��
����1����Ȼ�� b=0��gcd��a��b��=a����ʱ x=1��y=0��
����2��ab!=0 ʱ
������ ax1+by1=gcd(a,b);
����bx2+(a mod b)y2=gcd(b,a mod b);
�����������ص�ŷ�����ԭ���� gcd(a,b)=gcd(b,a mod b);
������:ax1+by1=bx2+(a mod b)y2;
������:ax1+by1=bx2+(a-(a/b)*b)y2=ay2+bx2-(a/b)*by2;
�������ݺ�ȶ���ã�x1=y2; y1=x2-(a/b)*y2;    //�ؼ�
    �������Ǿ͵õ������ x1,y1 �ķ�����x1��y1 ��ֵ���� x2��y2.
��  �����˼�����Եݹ鶨��ģ���Ϊ gcd ���ϵĵݹ����һ�����и�ʱ�� b=0�����Եݹ���Խ�����
*/
/*��2��ʹ����չŷ������㷨����������̵İ취��
    ���ڲ�����������pa+qb=c���� c mod Gcd(p, q)=0,��÷��̴��������⣬���򲻴��������⡣
    �����Ѿ��г���һ��������ķ��������ҵ�p * a+q * b = Gcd(p, q)��һ���p0,q0��p * a+q * b = Gcd(p, q)���������������㣺
    p = p0 + b/Gcd(p, q) * t
    q = q0 - a/Gcd(p, q) * t(����tΪ��������)
    ����pa+qb=c�������⣬ֻ�轫p * a+q * b = Gcd(p, q)��ÿ������� c/Gcd(p, q) ���ɡ�
    ���ҵ�p * a+q * b = Gcd(a, b)��һ���p0,q0��Ӧ���ǵõ�p * a+q * b = c��һ���p1 = p0*(c/Gcd(a,b)),q1 = q0*(c/Gcd(a,b))��
    p * a+q * b = c���������������㣺
    p = p1 + b/Gcd(a, b) * t
    q = q1 - a/Gcd(a, b) * t(����tΪ��������)
    p ��q����p * a+q * b = c�����������⡣
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
    int d=exgcd(b,a%b,x,y);  //d ����gcd(a,b)
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}

bool linear_equation(int a,int b,int c,int &x,int &y)
{
    int d = exgcd(a,b,x,y);  //���a*x+b*y = gcd(a,b)��һ���
    cout<<"a*x + b*y = gcd(a,b)��һЩ����"<<endl;
    cout<<x<<" "<<y<<endl;
    for(int t = 2; t < 10; t++){   //��� a*x + b*y = gcd(a,b)������һЩ��
        int x1 = x + b/d*t;
        int y1 = y - a/d*t;
        cout<<x1<<" " <<y1<<endl;
    }
    cout<<endl<<endl;
    if(c%d)
        return false;
    int k = c/d;    //��������� c/gcd(a,b)���� a*x +b*y = c�Ľ�
    x*=k; y*=k;    //��õ�ֻ������һ���
    return true;
}

int main(){
    //freopen("in.txt","r",stdin)��
    int a = 6,b = 15,c = 9;  //��� 6*x + 15*y = 9�Ľ�
    int x,y;
    int d = exgcd(a,b,x,y);
    if(!linear_equation(a,b,c,x,y))cout<<"�޽�"<<endl;
    cout<<"a*x + b*y = c��һЩ����"<<endl;
    cout<<x<<" "<<y<<endl;
    for(int t = 2; t < 10; t++){  //���������һЩ��
        int x1 = x + b/d*t;
        int y1 = y - a/d*t;
        cout<<x1<<" "<<y1<<endl;
    }
    return 0;
}
