//���Ƿֽⷨ��LU�ֽ⣩�������طֽ⣩
//�������A�ĸ�������ʽ��Ϊ0��A����Ψһ�ķֽ��һ����λ������L��һ���������������U�ĳ˻�


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
        for(int j = k; j <= n; j++){    //��L�ĵ�K��ȥ��U��ÿһ�У��õ�U�ĵ�K�У�j�ǵ�K�еĵ�j��
            double sum = 0;
            for(int i = 1; i < k; i++)   //i�����������j��֮ǰ�����ĺ�
                sum = sum+L[k][i]*U[i][j];
            U[k][j] = a[k][j] - sum;
        }
        for(int i = k; i <= n; i++){ //��L��ÿһ��ȥ��U�ĵ�K�У��õ�L�ĵ�K�У�����i�ǵ�K�еĵ�i��
            double sum = 0;
            for(int j = 1; j < k; j++) //j��ָ��i��ǰ������ĺ�
                sum = sum + L[i][j]*U[j][k];
            L[i][k] = (a[i][k]-sum)/U[k][k];
        }
    }
    cout<<"L�������£�"<<endl;
    for(int i = 1; i <= n; i++){//L����
        for(int j = 1; j <= n; j++){
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"U�������£�"<<endl;
    for(int i = 1; i <= n; i++){ //U����
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
     cout<<"���Է�����Ľ��ǣ�"<<endl;
     for(int i = 1; i <= n; i++)cout<<x[i]<<" ";
     cout<<endl;
}
/*
�������ݣ�
3
1 2 3
1 3 5
1 3 6
2 4 5
*/


