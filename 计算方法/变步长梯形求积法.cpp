//�䲽�����ι�ʽ���㷨ʵ��
//����˼��:������Ĺ����У�ͨ���Լ��������ȵĲ��Ϲ��ƣ��𲽸ı䲽������ηְ룩ֱ����������Ҫ��Ϊֹ
//��ʦ���鱾P138
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
const int maxn = 100 + 10;
double a,b,n,eps = 0.00001;

double f(double x){
    //return (x/(4+x*x));
    return 4/(1+x*x);
    //return sin(x);
    //return sin(x)/x;
}

int main(){
    freopen("in.txt","r",stdin);
    while(scanf("%lf%lf",&a,&b) != EOF){  //�����������Լ��ȷ���
        double h = b - a;   //һ��ʼ�ĵȷ����䣨�ֳ�һ�飩
        double T1 = (h/2)*(f(a) + f(b)),T2;   //��������������ʽ
        int n = 1;
        for(;;){
            double S = 0;
            for(double x = a + h/2; x < b; x += h)S += f(x);
            T2 = (T1 + h*S)/2;
            printf("����Ϊ %d ʱ, Tn = %8.6f, T2n = %8.6f\n",n,T1,T2);
            if(fabs(T2 - T1) < eps)break;
            T1 = T2,h /= 2,n *= 2;//n��¼����
        }
        printf("\n�����䲽�����������ʽ�õ��Ļ��ֽ���� :%8.6f\n",T2);
    }
    return 0;
}
/*
����
0 1
*/
/*
���
0.111566
*/

