//题目链接：http://codeforces.com/problemset/problem/893/B
//题目大意：就是输入一个数n，找出最大的Beautiful Divisors，且n能被这个Beautiful Divisors整除，其中Beautiful Divisors就是满足题目中的意思的数
//解题思路：先用数组保存这些数，然后从大到小枚举判断即可

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    int n,m;
    int a[15];
//  for(int i = 1; i < 15; i++)a[i] = a[i-1]*4+pow(2,i);//自己找的规律
    for(int i = 1; i < 15; i++)a[i] = (pow(2,i)-1)*pow(2,i-1);
    while(scanf("%d",&n) != EOF){
        for(int i = 14; i >= 1; i--)if(n%a[i] == 0&&n>=a[i]){
            printf("%d\n",a[i]);
            break;
        }
    }
    return 0;
}
