//普通的平方根法（Cholesky）求解对称正定矩阵

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;
const int maxn = 100+10;
double a[maxn][maxn],b[maxn],l[maxn][maxn],x[maxn],y[maxn];

int main(){
    FILE *in;
    int n;
    if((in = fopen("in.txt","r")) == NULL){cout<<"cannot open the file"<<endl;exit(0);}
    fscanf(in,"%d",&n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fscanf(in,"%lf",&a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++)fscanf(in,"%lf",&b[i]);
    double sum;
    for(int i = 1; i <= n; i++){   //平方根法求L*L(T)
        for(int j = 1; j <= i-1; j++){  // i = j+1, j+2 ...
            sum = 0;
            for(int k = 1; k <= j - 1; k++) sum += l[i][k] * l[j][k];//一定要注意这里不是l[i][k]*l[k][j]
            l[i][j] = (a[i][j] - sum)/l[j][j];
        }
        sum = 0;
        for(int k = 1; k <= i-1; k++)sum += (l[i][k]*l[i][k]);
        l[i][i] = sqrt(a[i][i] - sum);
    }
    cout<<"L矩阵如下 :"<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i = 1; i <= n; i++){
        double sum = 0;
        for(int j = 1; j <= i-1; j++)sum += l[i][j]*y[j];
        y[i] = (b[i] - sum)/l[i][i];
    }
    for(int i = 1; i <= n; i++)cout<<y[i]<<" ";cout<<endl;
    for(int i = 1; i <= n; i++){   //求转置矩阵
        for(int j = i+1; j <= n; j++){
            double temp = l[i][j];
            l[i][j] = l[j][i];
            l[j][i] = temp;
        }
    }
    for(int i = n; i >= 1; i--){
       double sum = 0;
        for(int j = i+1; j <= n; j++)sum += l[i][j]*x[j];
        x[i] = (y[i] - sum)/l[i][i];
    }
    for(int i = 1; i <= n; i++)cout<<x[i]<<" ";
    cout<<endl;
    return 0;
}
/*
3
1 1 2
1 2 0
2 0 11
5 8 7
*/

