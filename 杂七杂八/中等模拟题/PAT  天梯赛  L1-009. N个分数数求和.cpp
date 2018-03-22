//题目链接 : https://www.patest.cn/contests/gplt/L1-009
//题目大意 : 就是给你n个分数,然后求他们的和,输出整数和分数部分
//解题思路 : 直接逐个相加就可以,注意一些细节就可以

#include <iostream>
#include <stdio.h>
#include <math.h>
const int maxn = 100 + 10;
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b){ return b == 0 ?a: gcd(b,a%b); }
LL lcd(LL a,LL b){ return a/gcd(a,b)*b; }

int main(){
    int n;
    LL a[maxn],b[maxn];
    scanf("%d",&n);
    for(int i = 0; i < n; i++)scanf("%lld/%lld",&a[i],&b[i]);
    LL Zsum = a[0],Msum = b[0],Sum = 0; //Zsum代表分子,Msum代表分母
    for(int i = 1; i < n; i++){
        LL Lc = lcd(Msum,b[i]); //求出最小公倍数
        Zsum = Zsum*(Lc/Msum) + a[i]*(Lc/b[i]);
        Msum = Lc;
        if(fabs(Zsum) >= fabs(Msum)){
            Sum += Zsum/Msum; //整数部分
            Zsum -= (Zsum/Msum)*Msum; //约去整数部分
        }
        LL Gc = gcd(Zsum,Msum); //求出最大公因数
        Zsum /= Gc;
        Msum /= Gc;
    }
    if(Sum != 0 && Zsum != 0) printf("%lld %lld/%lld\n",Sum,Zsum,Msum);
    else if(Sum == 0 && Zsum != 0)printf("%lld/%lld\n",Zsum,Msum);
    else if(Sum != 0 && Zsum == 0)printf("%lld\n",Sum);
    else if(Sum == 0 && Zsum == 0)printf("0\n");
    return 0;
}

