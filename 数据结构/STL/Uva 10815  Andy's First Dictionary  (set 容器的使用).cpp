//题目链接：https://vjudge.net/contest/77100#problem/C
//题目大意：把一段文字中的符号去掉，并把单词排序
//解题思路：利用set容器


#include <iostream>
#include <stdio.h>
#include <set>
#include <sstream>

using namespace std;
set<string>s;
string str,buf;//buf 是缓存区，存储待读取的串

int main(){
    while(cin>>str){
        for(int i = 0; i < str.length(); i++){
            if(isalpha(str[i]))str[i] = towlower(str[i]);
            else str[i] = ' ';//把非单词变成空格（技巧）
        }
        stringstream ss(str);
        while(ss>>buf)s.insert(buf);
        }
        for(set<string>::iterator it = s.begin(); it != s.end(); it++){
            cout<<*it<<endl;
        }
    return 0;
}
