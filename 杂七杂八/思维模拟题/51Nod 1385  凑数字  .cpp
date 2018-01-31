//题目链接：http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1385
//题目大意：就是给你 一个数字n，问你 要多少个数字( 串 )才能组成 1 - n 的数
//解题思路: 这一题主要还是思维 + 规律 ，发现只要所有位数上数字相同或者达到10的次方，个数才加1，所以有下面的规律

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
char s[11000];

int main()
{
    scanf("%s",s);
    int len = strlen(s);
    int ans = (len-1)*10;
    int flag = 0;
    for(int i = 1; s[i] ; i++)
    {
        if(s[i] > s[0]){
            flag = 0;
            break;
        }
        else if(s[i] == s[0]) continue;
        else {
            flag = 1;
            break;
        }
    }
    printf("%d\n",ans + (s[0] - '0') - flag);
    return 0;
}
