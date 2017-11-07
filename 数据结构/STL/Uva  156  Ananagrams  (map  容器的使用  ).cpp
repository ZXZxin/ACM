//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/D
//��Ŀ����: ��һ��������ͨ����������ֻ��һ���ĵ��ʰ��ֵ��򣨴�д��ǰ�����
//����˼·������map������ͳ�Ƶ��ʵĸ���������vector�����¼


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
        ans[i] = towlower(ans[i]);//��дתСд
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    while(cin>>str&&str != "#"){
        words.push_back(str);
        string r = repr(str);
        if(!dict.count(r))dict[r] = 0;//count�Ǽ�������
        dict[r]++;//map������ʵҲ������һ����Ӧ�Ĺ�ϵ������ֱ�����ã�֧�������ַ����
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
