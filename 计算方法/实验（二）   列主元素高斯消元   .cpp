//���㷽��ʵ�飨��������Ԫ����Ԫ��

#include <stdio.h>  //����Ԫ����Ԫ��
#include <stdlib.h>//С��Ԫ���ܵ��¼���ʧ�ܣ���Ϊ�������ֵ��С�������������������ܴ�����Լ���м�����������������.
#include <cmath> //Ϊ�˱��ֳ���m[i][l]<=1
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
        for(int i = k+1; i <= n; i++)if(fabs(a[i][k]) > ans){ans = fabs(a[i][k]);maxi = i;} //�ڴ���Ԫ����������ÿһ��ѡȡ������Ϊ��Ԫ����Ԫ��
        for(int j = k; j <= n; j++){temp = a[k][j]; a[k][j] = a[maxi][j]; a[maxi][j] = temp;}  //������k�к͵�maxi��
        temp = b[k],b[k] = b[maxi],b[maxi] = temp;
        if(a[k][k] == 0){printf("gauss method does not run"); flag = false; break;}  //���a[k][k]Ϊ0 ,��������Ԫ����
        else {
            for(int i = k+1; i <= n; i++){
                for(int j = k+1; j <= n; j++)
                    a[i][j] = a[i][j]-a[k][j]*a[i][k]/a[k][k];
                b[i] = b[i]-b[k]*a[i][k]/a[k][k];
            }
        }
    }
    if(flag){
        for(int i = n; i > 0; i--){   //ע��:  �ش���ʱ��Ҫ��a[n][n] != 0
            double sum=0;
            for(int j = i+1; j <= n; j++) sum = sum+a[i][j]*x[j];
            x[i] = (b[i]-sum)/a[i][i];
        }
    }
    printf("���Է�����Ľ�Ϊ: \n");
    for(int i = 1; i <= n; i++)printf("x[%d] = %f\n",i,x[i]);
    return 0;
}
