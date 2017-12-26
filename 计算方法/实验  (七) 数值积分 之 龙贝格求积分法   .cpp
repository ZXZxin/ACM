//�����������������
//f�����������ϵ����⣬��������ȷ
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;
const int maxn = 100 + 10;
double a,b,eps = 1e-5;
double num[maxn][4];
int k;

double f(double x){
    return 4/(1+x*x);
}

void Romberg(double a,double b){
    k = 1;
    double T1,T2,S1,S2,C1,C2,R1,R2;
    double h = b - a;//һ��ʼ������
    T1 = (h/2)*(f(b) + f(a));
    num[0][0] = T1;
    for(;;){
        double sum = 0;
        for(double x = a + h/2; x < b; x += h)sum += f(x);
        T2 = (T1 + sum*h)/2;
        num[k][0] = T2;
        S2 = T2 + (T2 - T1)/3;//����
        num[k][1] = S2;
        if(k != 1){
             C2 = S2 + (S2 - S1)/15;//����ɭ
             num[k][2] = C2;
             if(k != 2){
                R2 = C2 + (C2 - C1)/63; //������
                num[k][3] = R2;
                if(k != 3)if(fabs(R2 - R1) < eps){printf("�����������ý����:  %8.6f\n\n",R2);break;}
                R1 = R2;
            }
            C1 = C2;
        }
        h /= 2;k++;//�𲽼�С����
        T1 = T2;
        S1 = S2;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%lf%lf",&a,&b) != EOF){//�������������
        memset(num,0,sizeof(num));
        Romberg(a,b);
        printf("�������㷨����������:\n");
        printf("%c%6c%12c%12c%12c\n",'k','T','S','C','R');
        for(int i = 0; i < k; i++){
            printf("%d  ",i);
            for(int j = 0; j < 4; j++){
                if(num[i][j] != 0)
                printf("%8.6f    ",num[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
����
0 1
*/
/*
���
�����������ý����:  3.141593

�������㷨����������:
k     T           S           C           R
0  3.000000
1  3.100000    3.133333
2  3.131176    3.141569    3.142118
3  3.138988    3.141593    3.141594    3.141586
*/


