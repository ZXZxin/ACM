//题目链接：https://vjudge.net/contest/171111#problem/C
//题目大意: 输入n,找出所有的x,y,x>=y,且 1/n = 1/x + 1/y ;(n,x,y > 0)
//解题思路: x < y  -->  1/x > 1/y  -->  1/n - 1/y >= 1/y  -->  y <= 2*n 所以只要 y 枚举到 2*n就可以了

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 100 + 10;
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int sum = 0;
        for(int y = n+1; y <= 2*n; y++)if((y*n)%(y - n) == 0)sum++;
        printf("%d\n",sum);
        for(int y = n+1; y <= 2*n; y++){
            if((y*n)%(y - n) == 0)printf("1/%d = 1/%d + 1/%d\n",n,(y*n)/(y- n),y);
        }
    }
    return 0;
}
