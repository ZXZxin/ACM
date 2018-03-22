//��Ŀ���� : https://www.patest.cn/contests/gplt/L1-009
//��Ŀ���� : ���Ǹ���n������,Ȼ�������ǵĺ�,��������ͷ�������
//����˼· : ֱ�������ӾͿ���,ע��һЩϸ�ھͿ���

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
    LL Zsum = a[0],Msum = b[0],Sum = 0; //Zsum�������,Msum�����ĸ
    for(int i = 1; i < n; i++){
        LL Lc = lcd(Msum,b[i]); //�����С������
        Zsum = Zsum*(Lc/Msum) + a[i]*(Lc/b[i]);
        Msum = Lc;
        if(fabs(Zsum) >= fabs(Msum)){
            Sum += Zsum/Msum; //��������
            Zsum -= (Zsum/Msum)*Msum; //Լȥ��������
        }
        LL Gc = gcd(Zsum,Msum); //����������
        Zsum /= Gc;
        Msum /= Gc;
    }
    if(Sum != 0 && Zsum != 0) printf("%lld %lld/%lld\n",Sum,Zsum,Msum);
    else if(Sum == 0 && Zsum != 0)printf("%lld/%lld\n",Zsum,Msum);
    else if(Sum != 0 && Zsum == 0)printf("%lld\n",Sum);
    else if(Sum == 0 && Zsum == 0)printf("0\n");
    return 0;
}

