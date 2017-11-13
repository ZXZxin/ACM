//��Ŀ���ӣ�https://vjudge.net/contest/77417#problem/D
//��Ŀ���⣺���ǿ������ÿһ��(a,b)�Ƿ�������������д���(b,a),��������ڣ������YES���������NO
//����˼·��ʹ��map����򵥵ģ���Ϥmap��ʹ���Լ�first,second�ķ���

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;
map<pair<int,int>,int>dict;
map<pair<int,int>,int>::iterator it;

bool Judge(){
    for(it = dict.begin(); it != dict.end(); it++){
        if(it->second)return false;//����ֱ����it->����map�е�Ԫ�أ�first��map�еĵ�һ��Ԫ�أ�second��map�еĵڶ���Ԫ��
    }
    return true;
}

int main(){
    //freopen("in.txt","r",stdin);
    int n,a,b;
    while(cin>>n&&n){
        dict.clear();
        for(int i = 0; i < n; i++){
            cin>>a>>b;
            a < b ? ++dict[make_pair(a,b)] : --dict[make_pair(b,a)];
        }
        if(Judge())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
