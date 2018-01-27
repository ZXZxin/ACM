//题目连接：http://acm.hdu.edu.cn/showproblem.php?pid=1496
//题目大意: 就是要你求  a*x1^2+b*x2^2+c*x3^2+d*x4^2=0  的 解的个数 给你 a,b,c,d，注意它们的范围
//解题思路: 直接暴力肯定超时，这个题目的解法 是 利用哈希的思想，感觉哈希的思想真的很神奇!

#include <iostream>
#include <stdio.h>
#include <string.h>

const int M = 2000000;  // 50 * 100^2 * 4
using namespace std;
int Hash[M + 3];  //这种大的数组一定要开成全局变量，不然程序容易奔溃

int main(){
    //freopen("in.txt","r",stdin);
    int a,b,c,d,sum,s[100+10];
    while(scanf("%d%d%d%d",&a,&b,&c,&d) != EOF){
        if((a>0 && b>0 && c>0 && d>0)||(a<0 && b<0 && c<0 && d<0)){printf("0\n");continue;} //因为x那项永远是正数
        sum = 0;
        memset(Hash,0,sizeof(Hash));
        for(int i = 1; i <= 100; i++)s[i] = i*i;
        for(int i = 1; i <= 100; i++){   //分成 2组 ，先计算 a*s[i] + b*s[j] 然后将对应的下标的个数存到Hash函数
            for(int j = 1; j <= 100; j++){
                Hash[a*s[i] + b*s[j] + M/2]++;  //防止下标是负数 所以加上 (50 * 100^2 * 4)/2
            }
        }
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                sum += Hash[-(c*s[i] + d*s[j]) + M/2];  //这个里面就是存的对应的一个解的个数
            }
        }
        printf("%d\n",sum*16); //因为 x 是平方，所以正负数的平方都一样，一个x就会有两个解了，4个x当然就有 2^4=16 组解
    }
    return 0;
}
