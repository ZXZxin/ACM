//题目链接：https://vjudge.net/contest/169966#problem/B
//题目大意及解题思路：从A->C和从C->B，例如要求顺序(B站的顺序)是[5,4,1,2,3]（即输入的），A中的原顺序是[1,2,3,4,5]（1到n）,
            //那么接下来有两个操作，如果B要求的第一个等于A中的第一个，那么直接从A->B，否则
            //如果C的栈顶等于B要求的第一个,那么C->B,如果都不是，那么只能A->C了
            //如果以上都不成立，也就是说A里面已经没有数据了，那说明该要求顺序是不可能出现的
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
const int maxn = 1000+10;

int n;
int target[maxn];
stack<int>s;

int main(){
    //freopen("in.txt","r",stdin);
    while(cin>>n&&n){
        while(cin>>target[1]&&target[1]!=0){
            for(int i = 2; i <= n; i++){
                cin>>target[i];
            }
            while(!s.empty())s.pop();
            int A = 1;//A站的数据（默认1-n）
            int B = 1;//输入的数据（B站的数据）
            bool flag = true;
            while(B <= n){
                if(target[B] == A){
                    A++;
                    B++;
                }
                else if(!s.empty()&&s.top() == target[B]){
                    s.pop();
                    B++;
                }
                else if(A <= n ){
                    s.push(A++);
                }
                else {flag = false ;break;}
            }
            if(!flag)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
