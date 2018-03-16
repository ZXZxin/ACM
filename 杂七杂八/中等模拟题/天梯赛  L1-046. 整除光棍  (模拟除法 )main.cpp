//题目链接 : https://www.patest.cn/contests/gplt/L1-046
//主要是思维 : 模拟除法的应用

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 10000 + 10;

int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    char s[maxn];
    scanf("%d",&n);
    int now = 1;
    int p = 0;
    for(int len = 1; ;len++){
        if(p || now/n)s[p++] = now/n + '0';
        now %= n;
        if(!now){
            s[p] = '\0';
            printf("%s %d\n",s,len);
            break;
        }
        now = now*10 + 1;
    }
    return 0;
}

