//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/C
//��Ŀ���⣺��һ�������еķ���ȥ�������ѵ�������
//����˼·������set����


#include <iostream>
#include <stdio.h>
#include <set>
#include <sstream>

using namespace std;
set<string>s;
string str,buf;//buf �ǻ��������洢����ȡ�Ĵ�

int main(){
    while(cin>>str){
        for(int i = 0; i < str.length(); i++){
            if(isalpha(str[i]))str[i] = towlower(str[i]);
            else str[i] = ' ';//�ѷǵ��ʱ�ɿո񣨼��ɣ�
        }
        stringstream ss(str);
        while(ss>>buf)s.insert(buf);
        }
        for(set<string>::iterator it = s.begin(); it != s.end(); it++){
            cout<<*it<<endl;
        }
    return 0;
}
