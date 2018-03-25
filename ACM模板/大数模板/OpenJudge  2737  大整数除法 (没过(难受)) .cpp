//题目链接 : http://bailian.openjudge.cn/practice/2737/
//模板除法 没过,难受

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

const int maxn = 10000 + 10;
using namespace std;

int BigInteger_Sub(int a[],int b[],int maxlen){  //减法的执行
    for(int i = 0; i < maxlen; i++){
        if(a[i] < b[i]){
            a[i] = a[i]+10-b[i];
            a[i+1] -= 1;
        }
        else a[i] -= b[i];
    }
    int i;
    for(i = maxlen-1; i >= 0; i--)if(a[i])return i+1;  //返回相减之后a的位数
}

int Judge(int a[],int b[],int len1,int len2){  //判断两个数的大小
    if(len1 < len2)return -1;
    else if(len1 > len2)return 1;
    else {
        for(int i = len1-1; i >= 0; i--){
            if(a[i] > b[i])return 1;
            else if(a[i] < b[i])return -1;
        }
        return 0; //相等
    }
}

string Mod; //保存余数
string BigInteger_sAndMod(char *s1,char *s2){
    if(s1 == s2){
        Mod = "0";
        return "1";
    }
    int len1 = strlen(s1),len2 = strlen(s2);
    if(len1 < len2){  //如果s1 < s2
        Mod = s1;
        return "0";
    }else {
        int a[maxn],b[maxn];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 0; i < len1; i++)a[i] = s1[len1-i-1] - '0'; // 63528
        for(int i = 0; i < len2; i++)b[i] = s2[len2-i-1] - '0'; // 32
        int originalenB = len2; //记录原来的长度
        int sublen = len1-len2;
        for(int i = len1-1; i >= 0; i--){  //28536 23  --> 28536 23000
            if(i >= sublen)b[i] = b[i-sublen];
            else b[i] = 0;
        }
        len2 = len1;
        int originalenA = len1,temp;
        int ans[maxn];
        for(int i = 0; i <= sublen; i++){
            ans[sublen-i] = 0;
            while(  ( temp = Judge(a,b,len1,len2) ) >= 0 && originalenA >= originalenB ){
                originalenA = BigInteger_Sub(a,b,len1);
                ans[sublen-i]++;
                len1 = originalenA;
                if(len1 < len2 && b[len2 - 1] == 0)len2 = len1;
            }
            if(temp < 0){
                int j;
                for(j = 1; j < len2; j++)b[j-1] = b[j];
                b[j-1] = 0;
                if(len1 < len2)len2--;
            }
        }
        string str = "";
        int i;
        for(i = sublen; i > 0; i--)if(ans[i])break;
        for(;i >= 0; i--)str += ans[i] + '0';
        for(i = len1; i > 0; i--)if(a[i])break;
        for(;i >= 0; i--)Mod += a[i] + '0';
        return str;
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    char s1[maxn],s2[maxn];
    while(~scanf("%s\n%s",s1,s2)){
        cout<<BigInteger_sAndMod(s1,s2)<<endl;
    }
    return 0;
}
