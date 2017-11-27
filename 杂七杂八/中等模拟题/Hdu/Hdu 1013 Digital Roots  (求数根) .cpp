//题目链接:http://acm.hdu.edu.cn/showproblem.php?pid=1013
//题目大意：给你一个数，每次分解出每一位上的数并相加，如果和小于10就输出这个和，否则继续分解
//解题思路：直接模拟不行，数可以很大，要用字符串模拟，而且每取一位计算后如果大于10就取模
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

typedef long long LL;

string s;
int main(){
    //freopen("in","r",stdin);
    while(cin>>s && s[0] != '0'){
        int d = 0;
        for(int i = 0; i < s.size(); i++){
            d += (s[i] - '0');//化为数字
            if(d >= 10)d = d/10 + d%10;  //这一步是关键所在
        }
        cout<<d<<endl;
    }
    return 0;
}
