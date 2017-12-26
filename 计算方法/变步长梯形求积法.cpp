//变步长梯形公式的算法实现
//基本思想:在求积的工程中，通过对计算结果精度的不断估计，逐步改变步长（逐次分半）直到精度满足要求为止
//刘师少书本P138
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const int maxn = 100 + 10;
double a,b,n,eps = 0.00001;

double f(double x){
    //return (x/(4+x*x));
    return 4/(1+x*x);
    //return sin(x);
    //return sin(x)/x;
}

int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%lf%lf",&a,&b) != EOF){  //积分上下限以及等分数
        double h = b - a;   //一开始的等分区间（分成一块）
        double T1 = (h/2)*(f(a) + f(b)),T2;   //最初的梯形求积公式
        int n = 1;
        for(;;){
            double S = 0;
            for(double x = a + h/2; x < b; x += h)S += f(x);
            T2 = (T1 + h*S)/2;
            printf("步长为 %d 时, Tn = %8.6f, T2n = %8.6f\n",n,T1,T2);
            if(fabs(T2 - T1) < eps)break;
            T1 = T2,h /= 2,n *= 2;//n记录步长
        }
        printf("\n经过变步长梯形求积公式得到的积分结果是 :%8.6f\n",T2);
    }
    return 0;
}
/*
输入
0 1
*/
/*
输出
0.111566
*/

