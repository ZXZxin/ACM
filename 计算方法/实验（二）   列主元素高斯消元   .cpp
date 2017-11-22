//计算方法实验（二）列主元素消元法

#include <stdio.h>  //列主元素消元法
#include <stdlib.h>//小主元可能导致计算失败，因为这个绝对值很小的数用作除数，乘数很大，引起约化中间结果数量级严重增长.
#include <cmath> //为了保持乘数m[i][l]<=1
#define N 1000
double a[N][N],b[N],x[N];

int main(){
    FILE *in;
    int n;
    if((in = fopen("in.txt","r")) == NULL){printf("cannot open the file\n");exit(0);}
    fscanf(in,"%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            fscanf(in,"%lf",&a[i][j]);
        fscanf(in,"%lf",&b[i]);
    }
    bool flag = true;
    for(int k = 1; k < n; k++){
        int maxi;
        double ans = a[k][k],temp;
        for(int i = k+1; i <= n; i++)if(fabs(a[i][k]) > ans){ans = fabs(a[i][k]);maxi = i;} //在待消元的所在列中每一次选取最大的作为消元的主元素
        for(int j = k; j <= n; j++){temp = a[k][j]; a[k][j] = a[maxi][j]; a[maxi][j] = temp;}  //交换第k行和第maxi行
        temp = b[k],b[k] = b[maxi],b[maxi] = temp;
        if(a[k][k] == 0){printf("gauss method does not run"); flag = false; break;}  //如果a[k][k]为0 ,则不满足消元条件
        else {
            for(int i = k+1; i <= n; i++){
                for(int j = k+1; j <= n; j++)
                    a[i][j] = a[i][j]-a[k][j]*a[i][k]/a[k][k];
                b[i] = b[i]-b[k]*a[i][k]/a[k][k];
            }
        }
    }
    if(flag){
        for(int i = n; i > 0; i--){   //注意:  回代的时候要求a[n][n] != 0
            double sum=0;
            for(int j = i+1; j <= n; j++) sum = sum+a[i][j]*x[j];
            x[i] = (b[i]-sum)/a[i][i];
        }
    }
    printf("线性方程组的解为: \n");
    for(int i = 1; i <= n; i++)printf("x[%d] = %f\n",i,x[i]);
    return 0;
}
