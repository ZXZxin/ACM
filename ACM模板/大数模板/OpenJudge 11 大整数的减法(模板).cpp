//题目链接 : http://noi.openjudge.cn/ch0106/11/
//大数减法的模板

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

const int maxn = 200 + 10;
using namespace std;
typedef long long LL;

string BigInteger_SubInfo(char *s1,char *s2){
    int a[maxn],b[maxn];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int len1 = strlen(s1),len2 = strlen(s2);
    int maxlen = max(len1,len2);
    for(int i = 0; i < len1; i++) a[i] = s1[len1 - i - 1] - '0';
    for(int i = 0; i < len2; i++) b[i] = s2[len2 - i - 1] - '0';
    for(int i = 0; i < maxlen; i++){
        if(a[i]-b[i] < 0){
            a[i] = a[i]+10-b[i];
            a[i+1] -= 1;
        }
        else a[i] -= b[i];
    }
    string str = "";
    int i;
    for(i = maxlen-1; i >= 0; i--)if(a[i] != 0)break;
    for(;i >= 0; i--)str += a[i]+'0';
    return str;
}

string BigInteger_Sub(char *s1,char *s2){
    if(s1 == s2)return "0"; //相等
    int len1 = strlen(s1),len2 = strlen(s2);
    if(len1 > len2)return BigInteger_SubInfo(s1,s2);
    else if(len1 < len2)return "-" + BigInteger_SubInfo(s2,s1); //负数
    else {  //长度相等时判断大小
        for(int i = 0; i < len1; i++){
            if(s1[i]-'0' > s2[i]-'0')return BigInteger_SubInfo(s1,s2);
            else if(s1[i]-'0' < s2[i]-'0')return "-" + BigInteger_SubInfo(s2,s1);
        }
    }
}

int main(){
    char s1[maxn],s2[maxn];
    scanf("%s\n%s",s1,s2);
    cout<<BigInteger_SubInfo(s1,s2)<<endl;
    return 0;
}

