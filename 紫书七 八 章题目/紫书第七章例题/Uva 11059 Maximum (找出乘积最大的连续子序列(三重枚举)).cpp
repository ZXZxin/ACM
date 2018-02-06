//题目链接:https://vjudge.net/contest/171111#problem/B
//题目大意:找出一个乘积最大的连续子序列，如果这个序列不是正数输出0
//解题思路: 枚举，三重循环，枚举起点和终点即可

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 10 + 10;
using namespace std;
typedef long long LL;

int main(){
    //freopen("in.txt","r",stdin);
    int n,kase = 0;
    int a[maxn];
    while(scanf("%d",&n) != EOF){
        LL maxx = 0;
        for(int i = 0; i < n; i++)scanf("%d",&a[i]);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){//注意这里不是从i + 1开始，因为可以一个数
                LL sum = 1;
                for(int k = i; k <= j; k++){
                    sum *= a[k];
                }
                maxx = max(maxx,sum);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",++kase,maxx);
    }
    return 0;
}
