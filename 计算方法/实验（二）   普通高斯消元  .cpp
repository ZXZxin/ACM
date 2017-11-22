//计算方法实验（二）
//普通高斯消元

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#define N 1000
using namespace std;
double a[N][N],b[N],x[N];
int main(){
    FILE *in;
    int n;
    if((in = fopen("in.txt","r")) == NULL){cout<<"cannot open the file"<<endl;exit(0);}
    fscanf(in,"%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            fscanf(in,"%lf",&a[i][j]);
        fscanf(in,"%lf",&b[i]);
    }
    int k;
    for(k = 1; k < n; k++){
        for(int i = k+1; i <= n; i++){
            for(int j = k+1; j <= n; j++) ///注意一定要从 K + 1开始
                a[i][j] = a[i][j]-a[k][j]*a[i][k]/a[k][k];
            b[i] = b[i]-b[k]*a[i][k]/a[k][k];
        }
        printf("经过第%d步后增广矩阵为：\n",k);
        for(int l = 1; l <= n; l++){
            for(int j = 1; j <= n; j++) printf("%f ",a[l][j]);
            printf("%f ",b[l]);
            printf("\n");
        }
    }
    for(int i = n; i > 0; i--){
        double sum = 0;
        for(int j = i+1; j <= n; j++) sum = sum+a[i][j]*x[j];
        x[i] = (b[i]-sum)/a[i][i];
    }
    printf("线性方程组的解为: \n");
    for(int i = 1; i <= n; i++){
        if(x[i] == 0)x[i] = fabs(x[i]);
        printf("x[%d]=%f\n",i,x[i]);
    }
    return 0;
}

/*
10
4 2 -3 -1 2 1 0 0 0 0 5
8 6 -5 -3 6 5 0 1 0 0 12
4 2 -2 -1 3 2 -1 0 3 1 3
0 -2 1 5 -1 3 -1 1 9 4 2
-4 2 6 -1 6 7 -3 3 2 3 3
8 6 -8 5 7 17 2 6 -3 5 46
0 2 -1 3 -4 2 5 3  0 1 13
16 10 -11 -9 17 34 2 -1 2 2 38
4 6 2 -7 13 9 2 0 12 4 19
0 0 -1 8 -3 -24 -8 6 3 -1 -21
*/



