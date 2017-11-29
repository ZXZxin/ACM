//高斯赛德尔迭代法，以及超松弛迭代法

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
const int M = 100;  //最大的迭代次数
const int maxn = 100;

double a[maxn][maxn],b[maxn],x[maxn],y[maxn];
int n;

int main(){
    freopen("in.txt","r",stdin);
    memset(x,0,sizeof(x));//选取初值全为0
    memset(y,0,sizeof(y));
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)cin>>b[i];
    double sum, maxx, eps = 0.000000001,w = 1;//当w = 1时就是高斯赛德尔迭代法
    bool flag = true;
    int k;
    for(k = 1; k <= M; k++){  //控制迭代次数
        for (int i = 1; i <= n ; i++ ){ //对i = 1,2,3,..n计算公式
            sum = 0;
            for(int i = 1; i <= n; i++ ) y[i] = x[i];//先把原来的值存好，等下判断退出的时候要用
            for (int j = 1; j <= n; j++)
                if(j != i) sum += a[i][j] * x[j];
            x[i] = ( b[i] - sum) / a[i][i]; //由x(k)计算出x(k+1)
            x[i] = (1 - w)*y[i]+w*x[i];//y[i]存的是原来的值
        }
        maxx = 0;
        for(int i = 1; i <= n; i++)
            if( maxx < fabs(x[i]-y[i])) maxx = fabs(x[i] - y[i]);//当相邻两次迭代结果的偏差max(x[i] - y[i]) < eps即小于给定的精度可以输出
        if ( maxx < eps ){flag = false; break;}
        printf( "\nk = %d, ",k);
        for(int i = 1; i <= n; i++ ) printf( "y[%d] = %lf ",i,y[i]);
    }
    if(flag)printf( "ERROR!\n");
    else {
        printf( "\nk = %d, ", k);
        for (int i = 1; i <= n; i++ ) printf( "y[%d] = %lf ", i, y[i] );
    }
    return 0;
}
/*
3
10 -1 -2
-1,10,-2
-1,-1,5
7.2,8.3,4.2
*/

/*
3
5 2 1
-1 4 2
2 -3 10
-12 20 3
*/
/*
3
8 -3 2
4 11 -1
6 3 12
20 33 36
*/

