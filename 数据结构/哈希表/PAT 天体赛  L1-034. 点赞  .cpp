//题目链接 : https://www.patest.cn/contests/gplt/L1-034
//哈希表的简单题

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 1000 + 10;

int main(){
    int n,k,x;
    int a[maxn];
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            scanf("%d",&x);
            a[x]++;
        }
    }
    int maxi = 1;
    for(int i = 2; i < 1002; i++){
        if(a[i] >= a[maxi])maxi = i;
    }
    printf("%d %d\n",maxi,a[maxi]);
    return 0;
}
