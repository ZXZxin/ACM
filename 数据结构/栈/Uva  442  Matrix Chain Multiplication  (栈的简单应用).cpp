//��Ŀ���ӣ�https://vjudge.net/contest/169966#problem/C
//��Ŀ���⣺�������ˣ�����n�������ά�Ⱥ�һЩ�������˱��ʽ������˷�����
           //�ٶ�A��m*n����B��n*p������ôAB��m*p���󣬳˷�����Ϊm*n*p,���A������������B����������˷��޷�����
//����˼·����ջ�������ʽ��������ĸ��ջ�����������ų�ջ�����㣬Ȼ��ṹ��ջ����Ϊ����Ϸ������Ų�����ջ


#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

struct node{
    int a,b;
    node(int a = 0,int b = 0):a(a),b(b){}
}m[26];

int n;
stack<node>s;
string str;

int main(){
    //freopen("in.txt","r",stdin);
    cin>>n;//fflush(stdin);
    for(int i = 0; i < n; i++){
        char ch;
        cin>>ch;//Ҳ������scanf("\n%c",&ch)
        //������scanf("%c",&ch);����ch = getchar();
        int k = ch - 'A';
        cin>>m[k].a>>m[k].b;
    }
    while(cin>>str){
        while(!s.empty())s.pop();
        int len = str.length();
        int sum = 0;
        bool flag = true;
        for(int i = 0; i < len; i++){
            if(isalpha(str[i]))s.push(m[str[i]-'A']);
            else if(str[i] == ')'){
                node y = s.top();s.pop();
                node x = s.top();s.pop();
                if(x.b != y.a){flag = false; break;}
                sum += x.a*x.b*y.b;
                s.push(node(x.a,y.b));
            }
        }
        if(flag)
            cout<<sum<<endl;
        else
            cout<<"error"<<endl;
    }
    return 0;
}
