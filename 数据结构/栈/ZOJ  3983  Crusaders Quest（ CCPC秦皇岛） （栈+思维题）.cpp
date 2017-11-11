//��Ŀ���ӣ�http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3983
//��Ŀ����: ����Ÿ��ַ����������ȥ���ٸ���������һ���
//����˼·����һ����ɨ�����ģ���ջ�������ڶ������ɾ�����е�ÿһ�������Կ��ܲ������еĶ����������������ȥ����Ϊ2������Ϊ1

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 15;
char str[maxn];
char res[3] = {'g','a','o'};
char stacks[maxn];
int top;

int main(){
    int T;
    cin>>T;
    while(T--) {
        cin>>str;
        top = 0;
        for(int i = 0;i < 9; i++){
            if(top >= 2 && str[i] == stacks[top] && stacks[top] == stacks[top-1])
            top -= 2;
            else stacks[++top] = str[i];
        }
        if(top == 0){cout<<3<<endl;continue;}
        else {
            int j;
            for(j = 0; j < 3; j++){
                top = 0;
                for(int i = 0; i < 9; i++){ //����ɾ�����е�ĳһ��
                    if(str[i] != res[j]){
                        if(top >= 2 && str[i] == stacks[top] && stacks[top] == stacks[top-1])top -= 2;
                        else stacks[++top] = str[i];
                    }
                } if(top == 0){cout<<2<<endl;break;}
            }if(j == 3)cout<<1<<endl;
        }
    }
    return 0;
}
