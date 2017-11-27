//三角分解法（LU分解）（杜立特分解）
//定理：如果A的各阶主子式不为0，A可以唯一的分解成一个单位下三角L和一个非奇异的上三角U的乘积


#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
const int maxn = 10+10;

double a[maxn][maxn],L[maxn][maxn],U[maxn][maxn];
double b[maxn],x[maxn],y[maxn];

int main(){
    int n;
    //freopen("in.txt","r",stdin);
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)cin>>b[i];
    memset(L,0,sizeof(L));
    memset(U,0,sizeof(U));
    for(int i = 1; i <= n; i++)U[1][i] = a[1][i];
    for(int i = 1; i <= n; i++)L[i][1] = a[i][1]/U[1][1];
    for(int k = 1; k <= n; k++){
        for(int j = k; j <= n; j++){    //用L的第K行去乘U的每一列，得到U的第K行，j是第K行的第j列
            double sum = 0;
            for(int i = 1; i < k; i++)   //i是用来计算第j列之前的数的和
                sum = sum+L[k][i]*U[i][j];
            U[k][j] = a[k][j] - sum;
        }
        for(int i = k; i <= n; i++){ //用L的每一行去乘U的第K列，得到L的第K列，其中i是第K列的第i行
            double sum = 0;
            for(int j = 1; j < k; j++) //j是指第i列前面的数的和
                sum = sum + L[i][j]*U[j][k];
            L[i][k] = (a[i][k]-sum)/U[k][k];
        }
    }
    cout<<"L矩阵如下："<<endl;
    for(int i = 1; i <= n; i++){//L矩阵
        for(int j = 1; j <= n; j++){
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"U矩阵如下："<<endl;
    for(int i = 1; i <= n; i++){ //U矩阵
        for(int j = 1; j <= n; j++){
            cout<<U[i][j]<<" ";
        }
        cout<<endl;
    }
     y[1] = b[1];
     for(int i = 2; i <= n; i++){
        double sum = 0;
        for(int k = 1; k < i; k++)sum += L[i][k]*y[k];
        y[i] = b[i] - sum;
     }
     x[n] = y[n]/U[n][n];
     for(int i = n - 1; i >= 1; i--){
        double sum = 0;
        for(int k = i+1; k <= n; k++)sum += U[i][k]*x[k];
        x[i] = (y[i]-sum)/U[i][i];
     }
     cout<<"线性方程组的解是："<<endl;
     for(int i = 1; i <= n; i++)cout<<x[i]<<" ";
     cout<<endl;
}
/*
测试数据：
3
1 2 3
1 3 5
1 3 6
2 4 5
*/


