//题目链接：http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3983
//题目大意: 给你九个字符，求可以消去多少个三个连在一起的
//解题思路：第一遍先扫三个的，用栈操作，第二遍遍历删除其中的每一个，尝试看能不能所有的都消除，如果可以消去，则为2，否则为1

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
                for(int i = 0; i < 9; i++){ //尝试删除其中的某一个
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
