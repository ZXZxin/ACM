//题目链接 : http://acm.hdu.edu.cn/showproblem.php?pid=1002
//大数加法的模板 : 注意返回的是string类型,不知道为什么char*类型不行

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 1e4 + 10;

string BigPositiveInteger_Add(char *s1,char *s2){   //可以说是计算大数的模板
    int a[maxn],b[maxn];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int len1 = strlen(s1),len2 = strlen(s2);
    int maxL = max(len1,len2);
    for(int i = 0; i < len1; i++)a[i] = s1[len1-1-i]-'0';
    for(int i = 0; i < len2; i++)b[i] = s2[len2-1-i]-'0';
    for(int i = 0; i < maxL; i++){
        if(a[i]+b[i] >= 10){
            int temp = a[i]+b[i];
            a[i] = temp%10;
            a[i+1] += (temp/10);
        }
        else a[i] += b[i];
    }
    string c = "";
    if(a[maxL] != 0) c += a[maxL] + '0';
    for(int i = maxL-1; i >= 0; i--)c += a[i] + '0';
    return c;
}


//乘法
string BigInteger_Multiply(string s1,string s2){
    int a[maxn],b[maxn],c[maxn*2 + 5];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int len1 = s1.size(),len2 = s2.size();
    for(int i = 0; i < len1; i++)a[i] = s1[len1-1-i]-'0'; //倒置
    for(int i = 0; i < len2; i++)b[i] = s2[len2-1-i]-'0';
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            c[i+j] += a[i]*b[j];
        }
    }
    for(int i = 0; i < maxn*2; i++){
        if(c[i] >= 10){
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }
    string ans = "";
    int i;
    for(i = maxn * 2; i >= 0; i--)if(c[i] != 0)break;
    for(;i >= 0; i--)ans += c[i] + '0';
    return ans;
}


int main(){
    //freopen("in.txt","r",stdin);
    int T,kase = 0;
    char s1[maxn],s2[maxn];
    scanf("%d",&T);
    while(T--){
        scanf("%s %s",s1,s2);
        printf("Case %d:\n%s + %s = ",++kase,s1,s2);
        cout<<BigPositiveInteger_Add(s1,s2)<<endl;
        if(T != 0)printf("\n");
    }
    return 0;
}
