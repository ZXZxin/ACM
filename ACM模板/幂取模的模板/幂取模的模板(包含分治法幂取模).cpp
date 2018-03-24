//幂取模的模板

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int maxn = 100 + 10;
using namespace std;
typedef long long LL;

//幂取模函数
LL powMod(LL a,LL n,LL Mod){
    LL res = 1;
    while(n > 0){
        if(n&1)res = (res*a)%Mod;
        a = (a*a)%Mod;
        n >>= 1;
    }
    return res;
}

//刘汝佳的分治法求解
int pow_Mod(int a,int n,int Mod){
    if(n == 0)return 1;
    int x = pow_Mod(a,n/2,Mod);
    LL ans = (LL)x*x%Mod;
    if(n&1)ans = ans*a%Mod;
    return (int)ans;
}

//程序中包含了测试时间的程序
int main(){
    clock_t start,finish;
    double Total_time;
    start = clock();

    cout<<powMod(2,11,2047)<<endl;//测试一下结果

    finish = clock();
    Total_time = (double)(finish-start)/CLOCKS_PER_SEC;
    cout<<Total_time<<endl;
    return 0;
}

