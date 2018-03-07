//题目链接 : https://www.patest.cn/contests/gplt/L1-011
//题目大意 : 就是要你去除 A 中出现 B 中的字符 ,然后输出
//解题思路 : 又是哈希的思想做的

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int maxn = 10000 + 1;
typedef long long LL;

int main(){
    //freopen("in.txt","r",stdin);
    char s1[maxn],s2[maxn],s3[maxn];
    int a[257 + 200] = {0};
    gets(s1);gets(s2);
    int len1 = strlen(s1),len2 = strlen(s2);
    for(int i = 0; i < len2; i++)a[s2[i] - '0'+200] = 1;
    int k = 0;
    for(int i = 0; i < len1; i++)if(!a[s1[i] - '0'+200])s3[k++] = s1[i];
    for(int i = 0; i < k; i++)printf("%c",s3[i]);
    printf("\n");
    return 0;
}
