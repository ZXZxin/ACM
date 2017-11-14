//题目链接：https://vjudge.net/contest/77417#problem/E
//题目大意: 就是找一组字符串中通过两个可以合成一个字符串的，把可以合成的那些按字典序输出
//解题思路：将输入的字符串存入set容器，然后枚举每一个，并且把每一个拆开成不同的等份，在set容器中查找

#include <stdio.h>
#include <iostream>
#include <set>
#include <string.h>
#include <string>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    set<string>dict;
    string s;
    while(cin>>s)dict.insert(s);
    for(set<string>::iterator it = dict.begin(); it != dict.end(); it++){
        s = *it;
        int len = s.length();
        for(int i = 0;i < len; i++){
            string s1 = s.substr(0,i+1);
            string s2 = s.substr(i+1,len-1);
            if(dict.find(s1) != dict.end()&&dict.find(s2) != dict.end()){
                cout<<s<<endl;
                break;
            }
        }
    }
    return 0;
}
