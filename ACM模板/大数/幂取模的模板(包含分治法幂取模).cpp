//��ȡģ��ģ��

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int maxn = 100 + 10;
using namespace std;
typedef long long LL;

//��ȡģ����
LL powMod(LL a,LL n,LL Mod){
    LL res = 1;
    while(n > 0){
        if(n&1)res = (res*a)%Mod;
        a = (a*a)%Mod;
        n >>= 1;
    }
    return res;
}

//����ѵķ��η����
int pow_Mod(int a,int n,int Mod){
    if(n == 0)return 1;
    int x = pow_Mod(a,n/2,Mod);
    LL ans = (LL)x*x%Mod;
    if(n&1)ans = ans*a%Mod;
    return (int)ans;
}

//�����а����˲���ʱ��ĳ���
int main(){
    clock_t start,finish;
    double Total_time;
    start = clock();

    cout<<powMod(2,11,2047)<<endl;//����һ�½��

    finish = clock();
    Total_time = (double)(finish-start)/CLOCKS_PER_SEC;
    cout<<Total_time<<endl;
    return 0;
}

