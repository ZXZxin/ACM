//题目链接 : https://www.patest.cn/contests/gplt/L1-005
//题目大意 : 就是要你查询
//解题思路 : 比较简单的哈希查询

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 1000 + 1;
typedef long long LL;

int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    LL a[maxn],x[maxn] = {0};
    int b[maxn],c[maxn],y[maxn],p[maxn];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%lld%d%d",&a[i],&b[i],&c[i]);
        x[b[i]] = a[i];
        y[b[i]] = c[i];
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        scanf("%d",&p[i]);
    }
    for(int i = 0; i < m; i++){
        printf("%lld %d\n",x[p[i]],y[p[i]]);
    }
    return 0;
}
