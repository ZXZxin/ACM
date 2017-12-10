//题目链接：http://acm.nyist.net/JudgeOnline/problem.php?pid=88
//题目大意：就是求出汉诺塔的移动次数
//解题思路：输出前面的次数，发现有规律，利用求阶乘的二分法求出2的n次幂 - 1

//学习汉诺塔的博客
//http://www.cnblogs.com/gyb333/archive/2012/12/24/Hanoi.html
//http://blog.csdn.net/computerme/article/details/18080511

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
const int maxn = 1000000+10;
typedef long long LL;

LL sum;
void Move(LL n,char x,char y,char z){ //汉诺塔的递归
    sum++;
    if(n == 1){
        return ;
        printf("%c --> %c\n",x,z);
    }
    else {
        Move(n-1,x,z,y);
        printf("%c --> %c\n",x,z);
        Move(n-1,y,x,z);
    }
}

int pow_mod(int a,int b,int mod){//求a的b次方取模mod
    if(b == 0)return 1;//b为0时返回1
    long long x = pow_mod(a,b/2,mod);
    long long ans = (long long)x*x%mod;
    if(b&1)ans = ans * a % mod;
    return (int)ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",pow_mod(2,n,1000000) - 1);
    }
    return 0;
}


