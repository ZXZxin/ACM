//改进的平方根法求解对称矩阵
//分解成A = LDL(T) ,其中D是对角阵，L是单位下三角阵

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

const int maxn = 4;
int main(){
    FILE *in;
    int n;
    double a[maxn][maxn],b[maxn],d[maxn],l[maxn][maxn],x[maxn],y[maxn];
    double sum;
    if((in = fopen("in.txt","r")) == NULL){cout<<"cannot open the file"<<endl;exit(0);}
    fscanf(in,"%d",&n);
    memset(l,0,sizeof(l));
    memset(d,0,sizeof(d));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            fscanf(in,"%lf",&a[i][j]);
    }
    for(int i = 1; i <= n; i++)fscanf(in,"%lf",&b[i]);
    fclose(in);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i-1; j++){
            double sum = 0;
            for(int k = 1; k <= j - 1; k++) sum += d[k]*l[i][k]*l[j][k];
            l[i][j] = (a[i][j] - sum)/d[j];
        }
        sum = 0;
        for(int k = 1; k <= i-1; k++) sum += d[k]*l[i][k]*l[i][k];
        d[i] = a[i][i]-sum;
    }
    cout<<"D矩阵是："<<endl;
    for(int i = 1; i <= n; i++)cout<<d[i]<<" ";//只有主对角线上有元素的对角阵
    cout<<endl;
    for(int i = 1; i <= n; i++)l[i][i] = 1;  //把对角线上的赋值为1
    cout<<"L矩阵是："<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout<<l[i][j]<<" ";
        cout<<endl;
    }
    for(int i = 1; i <= n; i++){
        sum = 0;
        for(int k = 1; k <= i-1; k++) sum += l[i][k]*y[k];
        y[i] = b[i]-sum;
    }
    for(int i = n; i >= 1; i--){
        sum = 0;
        for(int k = i+1; k <= n; k++) sum += l[k][i]*x[k];
        x[i] = y[i]/d[i]-sum;
    }
    for(int i = 1; i <= n; i++)
        printf("x[%d] = %lf\n",i,x[i]);
    return 0;
}
/*
3
1 1 2
1 2 0
2 0 11
5 8 7
*/
