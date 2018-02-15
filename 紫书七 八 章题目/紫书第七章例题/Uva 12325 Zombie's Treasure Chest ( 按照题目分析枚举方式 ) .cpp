//题目链接：https://vjudge.net/contest/172005#problem/K
//题目大意: 就是给你n,s1,v1,s2,v2代表箱子容量,1的体积,价值,2的体积,价值,要你计算最多能装多大的价值
//解题思路: 这题主要是分三种枚举,因为如果只是枚举n/s1的话,如果s1很小就会超时,如果s1和s2都很小也会超时
            //这时候要看到 枚举s2个 * s1 = s1个 * s2 的体积相等,如果前者v大于后者,那么2最多拿s1 - 1个,
            //所以枚举到各自的体积就行

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 100 + 10;
using namespace std;
typedef long long LL;

int main(){
    //freopen("in.txt","r",stdin);
    int T,n,s1,v1,s2,v2,kase = 0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d%d",&n,&s1,&v1,&s2,&v2);
        if(s1 < s2){
            swap(s1,s2);
            swap(v1,v2);
        }
        LL maxx = 0;
        if( n / s1 >= 65536){ //两个都很小//这样枚举量就会很大 s2个 * s1 = s1个 * s2 的体积相等,如果前者v大于后者,那么2最多拿s1 - 1个
            for(LL i = 0; i <= s1; i++){ //枚举拿s1个宝物2
                maxx = max(maxx, v2*i + (n - s2*i)/s1*v1);
            }
            for(LL i = 0; i <= s2; i++){ //枚举拿s2个宝物1
                maxx = max(maxx, v1*i + (n - s1*i)/s2*v2);
            }
        }else for(LL i = 0; i <= n/s1; i++){  //否则就枚举比少的那一个
            maxx = max(maxx, i*v1 + (n - s1*i)/s2*v2);
        }
        printf("Case #%d: %lld\n",++kase,maxx);
    }
    return 0;
}
