//��Ŀ���ӣ�https://vjudge.net/contest/77417#problem/E
//��Ŀ����: ������һ���ַ�����ͨ���������Ժϳ�һ���ַ����ģ��ѿ��Ժϳɵ���Щ���ֵ������
//����˼·����������ַ�������set������Ȼ��ö��ÿһ�������Ұ�ÿһ���𿪳ɲ�ͬ�ĵȷݣ���set�����в���

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
