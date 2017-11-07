//题目链接：https://vjudge.net/contest/77100#problem/D
//题目大意: 把一段文字中通过排序后计数只有一个的单词按字典序（大写在前）输出
//解题思路：利用map容器，统计单词的个数，并用vector保存记录


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int>dict;
vector<string>words;
string str;

string repr(const string & s){
    string ans = s;
    for(int i = 0; i < ans.size(); i++){
        ans[i] = towlower(ans[i]);//大写转小写
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    while(cin>>str&&str != "#"){
        words.push_back(str);
        string r = repr(str);
        if(!dict.count(r))dict[r] = 0;//count是计数函数
        dict[r]++;//map容器其实也是类似一个对应的关系，可以直接引用，支持随机地址访问
    }
    vector<string>res;
    for(int i = 0; i < words.size(); i++){
        if(dict[repr(words[i])] == 1)res.push_back(words[i]);
    }
    sort(res.begin(),res.end());
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
