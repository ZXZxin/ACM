//题目链接 : https://www.patest.cn/contests/gplt/L1-039
//注意后面的空格

#include <iostream>
#include <stdio.h>
#include <string.h>

const int maxn = 1000 + 30;
using namespace std;

int main(){
    char str[maxn];
    int n;
    scanf("%d\n",&n);
    char s[maxn][maxn];
    memset(s,' ',sizeof(s)); //注意这个
    gets(str);
    int len = strlen(str);

    int num;
    if(len%n)num = len/n + 1;
    else num = len/n;

    int i = 0,p = 0,q = num-1;
    while(true){
        s[i++][q] = str[p++];
        if(len == p) break;
        if(p%n == 0)q--, i = 0;
    }

    for(i = 0; i < n; i++){
        for(int j = 0; j < num; j++)printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}
