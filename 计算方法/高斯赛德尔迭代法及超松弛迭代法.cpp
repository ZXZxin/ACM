//��˹���¶����������Լ����ɳڵ�����

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
const int M = 100;  //���ĵ�������
const int maxn = 100;

double a[maxn][maxn],b[maxn],x[maxn],y[maxn];
int n;

int main(){
    freopen("in.txt","r",stdin);
    memset(x,0,sizeof(x));//ѡȡ��ֵȫΪ0
    memset(y,0,sizeof(y));
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)cin>>b[i];
    double sum, maxx, eps = 0.000000001,w = 1;//��w = 1ʱ���Ǹ�˹���¶�������
    bool flag = true;
    int k;
    for(k = 1; k <= M; k++){  //���Ƶ�������
        for (int i = 1; i <= n ; i++ ){ //��i = 1,2,3,..n���㹫ʽ
            sum = 0;
            for(int i = 1; i <= n; i++ ) y[i] = x[i];//�Ȱ�ԭ����ֵ��ã������ж��˳���ʱ��Ҫ��
            for (int j = 1; j <= n; j++)
                if(j != i) sum += a[i][j] * x[j];
            x[i] = ( b[i] - sum) / a[i][i]; //��x(k)�����x(k+1)
            x[i] = (1 - w)*y[i]+w*x[i];//y[i]�����ԭ����ֵ
        }
        maxx = 0;
        for(int i = 1; i <= n; i++)
            if( maxx < fabs(x[i]-y[i])) maxx = fabs(x[i] - y[i]);//���������ε��������ƫ��max(x[i] - y[i]) < eps��С�ڸ����ľ��ȿ������
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

