//��Ŀ���ӣ�https://vjudge.net/contest/77100#problem/E
//��Ŀ���⣺
          /*һ��ջ����5�ֲ�����
            PUSH����ջ�з�һ���ռ��ϡ�
            DUP������ջ�����ϡ�
            UNION��ȡջ�����������ϣ�ȡ������Żء�
            INTERSECT��ȡջ�����������ϣ�ȡ������Żء�
            ADD��ȡջ���������ϣ�����һ��������ΪԪ�طŵ��ڶ��������У������ڶ������ϷŻ�ջ��
            ÿ�β��������ջ��������Ԫ�صĸ�����*/
//����˼·�������Ŀ����˺þã����Ѽ���ӳ���ID��ÿ�����϶�Ӧ��һ��ID�������������û�г��ֹ�������ͨ��IDȡ����

#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>//set_onion���������ͷ�ļ���

using namespace std;

typedef set<int>Set;
map<Set,int>IDcache;//�Ѽ���ӳ���ID
vector<Set>Setcache;//����IDȡ����

int ID(Set x){
    if(IDcache.count(x))return IDcache[x];//������־ͷ��ؼ��ϵ�ID
    Setcache.push_back(x);//���û�оͷ���һ���µ�ID
    IDcache[x] = Setcache.size() - 1;
    return Setcache.size() - 1;
}

int main(){
    //freopen("in.txt","r",stdin);
    int T,n;
    cin>>T;
    while(T--){
        stack<int>s;
        cin>>n;
        for(int i = 0; i < n; i++){
            string str;
            cin>>str;
            if(str == "PUSH") s.push(ID(Set()));//Set()��ָһ���յ�Set�ͽṹ��
            else if(str == "DUP") s.push(s.top());
            else{
                Set x1 = Setcache[s.top()]; s.pop();//x1��ʾջ��Ԫ�ؼ���//s.top()����ID
                Set x2 = Setcache[s.top()]; s.pop();
                Set x;
                if(str == "UNION")set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                if(str == "INTERSECT")set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                if(str == "ADD"){x = x2; x.insert(ID(x1));}
                s.push(ID(x));
            }
            cout<<Setcache[s.top()].size()<<endl;//Setcache[s.top()]��ʾջ��Ԫ�ؼ���//ע������Ľṹ��Ƕ��
        }
        cout<<"***"<<endl;
    }
    return 0;
}
