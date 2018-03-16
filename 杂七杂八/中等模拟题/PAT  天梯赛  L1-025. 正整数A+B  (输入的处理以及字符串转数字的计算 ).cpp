//题目链接 : https://www.patest.cn/contests/gplt/L1-025
//主要是输入的处理.....

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 10000 + 10;

int format(char *s){ //字符串转数字
    int sum = 0;
    int len = strlen(s);
    for(int i = 0; i < len ; i++){
        if(s[i] >= '0' && s[i] <= '9')sum = 10*sum + (s[i]-'0');
        else return -1;
    }
    if(sum > 0 && sum <= 1000){
        return sum;
    }
    return -1;
}

int main(){
    char s1[maxn],s2[maxn];
    scanf("%s ",s1); //这个空格用的很妙
    gets(s2);
    int a = format(s1);
    int b = format(s2);
    if(a > 0 && b > 0){
        printf("%d + %d = %d\n",a,b,a+b);
    }else if(a > 0 && b < 0){
        printf("%d + ? = ?\n",a);
    }else if(a < 0 && b > 0){
        printf("? + %d = ?\n",b);
    }else {
        printf("? + ? = ?\n");
    }
    return 0;
}
