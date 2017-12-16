//计算方法：拉格朗日插值算法插值函数

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int maxn = 100 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    double x[maxn],y[maxn],X;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)scanf("%lf",&x[i]);
    for(int i = 0; i < n; i++)scanf("%lf",&y[i]);
    while(scanf("%lf",&X) != EOF){
        double sum = 0;
        for(int i = 0; i < n; i++){
            double temp = 1;
            for(int j = 0; j < n; j++){
                if(i != j){
                    temp *= (X - x[j])/(x[i] -x[j]);
                }
            }
            sum += temp*y[i];
        }
        printf("%lf\n",sum);
    }
    return 0;
}
/*
6
0.4 0.55 0.65 0.80 0.95 1.05
0.41075 0.57815 0.69675 0.90 1.00 1.25382
0.596
*/
