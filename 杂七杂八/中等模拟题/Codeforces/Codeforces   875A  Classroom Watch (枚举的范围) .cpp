//题目链接：http://codeforces.com/problemset/problem/876/C
//题目大意：就是给你一个数，求可以满足的数，这些数满足自己本身加上每一位上的数（个位、十位等等）等于输入的数
//解题思路：题目不难，模拟即可，但是要注意枚举的数量，这点是关键，因为最大只有10的9次方，只需要枚举到小于这个数前面81个数即可

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include<cmath>
using namespace std;
const int maxn = 1000 + 10;
int main(){
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    long i, temp, sum, n;
    int res[100],ans = 0;
    cin>>n;
    for (i = n - 90; i < n; ++i){  //这一步是关键，只需要枚举小于9*9的数
        sum = i,temp = i;
        while (temp > 0){
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == n){
            res[ans++] = i;
        }
    }
    printf("%d\n", ans);
    for (i = 0; i < ans; i++)printf("%ld\n", res[i]);
    return 0;
}
