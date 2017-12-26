//复化梯形求积法的算法实现
//计算方法刘师少P134(梯形公式)，P135(辛普森)
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const int maxn = 100 + 10;
double a,b,n;

double f(double x){
    return sin(x);
}

double FuHuaTiXing(double a,double b,double n){//复化梯形求积公式
    double h = (b - a)/n;//步长
    double T = 0;
    for(int i = 1; i <= n - 1; i++)T += f(a + i*h);
    T = (h/2)*(f(a) + 2*T + f(b));
    return T;
}

double FuHuaXingPuSeng(double a,double b,double n){//复化辛普森求积公式
    double h = (b - a)/n;
    double S1 = f(a + h/2),S2 = 0,S;
    for(int i = 1; i <= n - 1; i++){
        S1 += f(a + i*h + h/2);
        S2 += f(a + i*h);
    }
    S = (h/6)*(f(a) + 4*S1 + 2*S2 + f(b));
    return S;
}

int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%lf%lf%lf",&a,&b,&n) != EOF){//积分上下限以及等分数
        printf("复化梯形求出来的积分是： %6.6f\n",FuHuaTiXing(a,b,n));
        printf("复化辛普森求出来的积分是： %6.6f\n",FuHuaXingPuSeng(a,b,n));
    }
    return 0;
}
/*
输入
1 2 8
*/
/*
输出
0.955203
0.956449
*/
