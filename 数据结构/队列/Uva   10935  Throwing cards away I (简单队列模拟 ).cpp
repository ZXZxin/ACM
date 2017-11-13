//题目链接：https://vjudge.net/contest/77417#problem/C
//题目大意：就是模拟队列，输入n，一叠牌从1到n编号先拿掉一张牌，然后把第二张放到队尾,直到只剩一张牌，输出拿掉的牌和剩余的牌
//解题思路：队列模拟即可

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    queue<int>q;
    while(cin>>n&&n){
        while(!q.empty())q.pop();
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        if(n < 2){cout<<"Discarded cards:"<<endl; cout<<"Remaining card: "<<q.front()<<endl;continue;}//这个输出格式真的服
        cout<<"Discarded cards: ";
        while(q.size() != 2){
            cout<<q.front()<<", ";
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<endl;
        q.pop();
        cout<<"Remaining card: "<<q.front()<<endl;
    }
    return 0;
}
