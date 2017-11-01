//题目链接：https://vjudge.net/contest/169966#problem/C
//题目大意：矩阵链乘，输入n个矩阵的维度和一些矩阵链乘表达式，输出乘法次数
           //假定A是m*n矩阵，B是n*p矩阵，那么AB是m*p矩阵，乘法次数为m*n*p,如果A的列数不等于B的行数，则乘法无法进行
//解题思路：用栈解析表达式，遇到字母入栈，遇到右括号出栈并计算，然后结构入栈，因为输入合法，括号不用入栈


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
        cin>>ch;//也可以用scanf("\n%c",&ch)
        //不能用scanf("%c",&ch);或者ch = getchar();
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
