//题目连接：http://acm.hdu.edu.cn/showproblem.php?pid=3833
//题目大意：就是找出数列中是否有满足P[i1]-P[i2]=P[i2]-P[i3], 1<=i1<i2<i3<=N.的存在
//解题思路：将a[i]的值作为hash函数对应的下标每次输入一个hash函数的值就加1,然后hash表中寻找，
           //在hash[i]的对称的前面和后面查找，如果hash[i-j]+hash[i+j]==1, 说明在i出现时，有两种可能，一是比i小的数已经出现但比i大的数还没出现，
           //或者比i大的数已经出现，比i小的数还没出现，没出现的数在i的后面，已经出现的在i的前面，这就找到了满足题意的序列。
           //需要注意的是，题目说的是1到N的序列，不是说随便的N个数。

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 10000 + 10;
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    int a[maxn],hash[maxn];
    while(T--){
        scanf("%d",&n);
        memset(hash,0,sizeof(hash));
        bool flag = false;
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            hash[a[i]]++;
            for(int j = 1; j < a[i] && j + a[i] <= n; j++){
                if(hash[a[i] - j] + hash[a[i] + j] == 1){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
